/*
 * Copyright (c) 2020, 2023 IoT.bzh
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <soc.h>
#include <zephyr/drivers/ipm.h>
#include <zephyr/drivers/clock_control.h>
#include <zephyr/drivers/clock_control/renesas_cpg_mssr.h>
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(rcar_ipm, LOG_LEVEL_DBG);

#define DT_DRV_COMPAT renesas_rcar_mfis

#if defined(CONFIG_SOC_SERIES_RCAR_GEN3)
/* Cortex A53/A57 -> Cortex R7 */
#define MFISARIICR0 0x400	/* rx req */
#define MFISARIICR1 0x408 	/* tx ack */
/* Cortex R7 -> Cortex A53/A57 */
#define MFISAREICR0 0x404 	/* rx ack */
#define MFISAREICR1 0x40c 	/* tx req */
#elif defined (CONFIG_SOC_SERIES_RCAR_GEN4)
/* Cortex A76 -> Cortex R52 */
#define MFISARIICR0 0x1400 	/* rx req */
#define MFISARIICR1 0x2408	/* tx ack */
/* Cortex R52 -> Cortex A76 */
#define MFISAREICR0 0x9404	/* rx ack */
#define MFISAREICR1 0x940c	/* tx req */
#endif

static K_SEM_DEFINE(send_sem, 0, 1);

/* Config MFIS */
struct rcar_mfis_config {
	uint32_t reg_addr;
	const struct device *clock_dev;
	struct rcar_cpg_clk mod_clk;
	void (*irq_config_func)(const struct device *dev);
};

struct rcar_mfis_data {
	ipm_callback_t callback;
	void *user_data;
};

#define RCAR_MFIS_CTRL_INTR		BIT(0)
#define RCAR_MFIS_CTRL_TX       BIT(1)

static void rcar_mfis_rx_isr(const struct device *dev)
{
	const struct rcar_mfis_config *config = dev->config;
	const struct rcar_mfis_data *data = dev->data;
	unsigned int value = 0;
	uint32_t reg_val;
	
	if (data->callback)
		data->callback(dev, data->user_data, 0, &value);

	/* Clear interrupt */
	reg_val = sys_read32(config->reg_addr + MFISARIICR0);
	reg_val &= ~RCAR_MFIS_CTRL_INTR;
	sys_write32(reg_val, config->reg_addr + MFISARIICR0);

	/* rx ack */
	reg_val = sys_read32(config->reg_addr + MFISAREICR0);
	reg_val |= RCAR_MFIS_CTRL_INTR;
	sys_write32(reg_val, config->reg_addr + MFISAREICR0);
}

static void rcar_mfis_tx_isr(const struct device *dev)
{
	const struct rcar_mfis_config *config = dev->config;
	uint32_t reg_val;
	/* Clear interrupt */
	reg_val = sys_read32(config->reg_addr + MFISARIICR1);
	reg_val &= ~RCAR_MFIS_CTRL_INTR;
	sys_write32(reg_val, config->reg_addr + MFISARIICR1);

	reg_val = sys_read32(config->reg_addr + MFISAREICR1);
	reg_val &= ~RCAR_MFIS_CTRL_TX;
	sys_write32(reg_val, config->reg_addr + MFISAREICR1);
	k_sem_give(&send_sem);
}

static int is_channel_busy(uint32_t reg)
{
	return sys_read32(reg) & RCAR_MFIS_CTRL_TX;
}

static int rcar_mfis_ipm_send(const struct device *dev, int wait, uint32_t id,
			   const void *data, int size)
{
	const struct rcar_mfis_config *config = dev->config;
	uint32_t reg_val;
	int err;
	while(is_channel_busy(config->reg_addr + MFISAREICR1))
		;
	/* Mark the channel as busy */
	reg_val = sys_read32(config->reg_addr + MFISAREICR1);
	reg_val |= RCAR_MFIS_CTRL_TX;
	/* Raise interrupt on other side */
	reg_val |= RCAR_MFIS_CTRL_INTR;
	sys_write32(reg_val, config->reg_addr + MFISAREICR1);
	err = k_sem_take(&send_sem, Z_TIMEOUT_MS(500));

	return err;
}

static int rcar_mfis_ipm_max_data_size_get(const struct device *dev)
{
	return 0;
}

static uint32_t rcar_mfis_ipm_max_id_val_get(const struct device *dev)
{
	return 0;
}

static void rcar_mfis_ipm_register_callback(const struct device *dev,
					 ipm_callback_t cb,
					 void *user_data)
{
	struct rcar_mfis_data *driver_data = dev->data;
	driver_data->callback = cb;
	driver_data->user_data = user_data;
}

static int rcar_mfis_ipm_set_enabled(const struct device *dev, int enable)
{
	return 0;
}

static int rcar_mfis_init(const struct device *dev)
{
	const struct rcar_mfis_config *config = dev->config;
	int ret;
	ret = clock_control_on(config->clock_dev,
			       (clock_control_subsys_t *) &config->mod_clk);
	if (ret < 0) {
		return ret;
	}

	config->irq_config_func(dev);

	/* TODO: add unlock of Write Protection register here (0xE6260900) ? */

	return 0;
}

static const struct ipm_driver_api rcar_mfis_driver_api = {
	.send = rcar_mfis_ipm_send,
	.register_callback = rcar_mfis_ipm_register_callback,
	.max_data_size_get = rcar_mfis_ipm_max_data_size_get,
	.max_id_val_get = rcar_mfis_ipm_max_id_val_get,
	.set_enabled = rcar_mfis_ipm_set_enabled
};

static void rcar_mfis_config_func(const struct device *dev);

static const struct rcar_mfis_config rcar_mfis_config = {
	.reg_addr = DT_INST_REG_ADDR(0),
	.irq_config_func = rcar_mfis_config_func,
	.clock_dev = DEVICE_DT_GET(DT_INST_CLOCKS_CTLR(0)),
	.mod_clk.module = DT_INST_CLOCKS_CELL(0, module),
	.mod_clk.domain = DT_INST_CLOCKS_CELL(0, domain),
};

static struct rcar_mfis_data rcar_mfis_data;

DEVICE_DT_INST_DEFINE(0, &rcar_mfis_init, NULL,
		    &rcar_mfis_data, &rcar_mfis_config,
		    PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT,
		    &rcar_mfis_driver_api);

static void rcar_mfis_config_func(const struct device *dev)
{
	IRQ_CONNECT(DT_INST_IRQ_BY_NAME(0, rxo, irq),
		    DT_INST_IRQ_BY_NAME(0, rxo, priority),
		    rcar_mfis_rx_isr, DEVICE_DT_INST_GET(0), 0);

	IRQ_CONNECT(DT_INST_IRQ_BY_NAME(0, txf, irq),
		    DT_INST_IRQ_BY_NAME(0, txf, priority),
		    rcar_mfis_tx_isr, DEVICE_DT_INST_GET(0), 0);

	irq_enable(DT_INST_IRQ_BY_NAME(0, rxo, irq));
	irq_enable(DT_INST_IRQ_BY_NAME(0, txf, irq));
}
