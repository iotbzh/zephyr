/*
 * Copyright (c) 2023 EPAM Systems
 * Copyright (c) 2023 IoT.bzh
 *
 * r8a779f0 Clock Pulse Generator / Module Standby and Software Reset
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT renesas_r8a779f0_cpg_mssr

#include <errno.h>
#include <zephyr/arch/cpu.h>
#include <zephyr/drivers/clock_control.h>
#include <zephyr/drivers/clock_control/renesas_cpg_mssr.h>
#include <zephyr/dt-bindings/clock/renesas_cpg_mssr.h>
#include <zephyr/dt-bindings/clock/r8a779f0_cpg_mssr.h>
#include <zephyr/irq.h>
#include "clock_control_renesas_cpg_mssr.h"

#define LOG_LEVEL CONFIG_CLOCK_CONTROL_LOG_LEVEL
#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(clock_control_rcar);

struct r8a779f0_cpg_mssr_cfg {
	DEVICE_MMIO_ROM; /* Must be first */
};

struct r8a779f0_cpg_mssr_data {
	struct rcar_cpg_mssr_data cmn; /* Must be first */
};

/* NOTE: the array MUST be sorted by module field */
static struct cpg_clk_info_table core_props[] = {
	RCAR_CORE_CLK_INFO_ITEM(R8A779F0_CLK_S0D12_PER, RCAR_CPG_NONE,
				RCAR_CPG_NONE, RCAR_CPG_KHZ(66660)),

	RCAR_CORE_CLK_INFO_ITEM(R8A779F0_CLK_CL16M, RCAR_CPG_NONE,
				RCAR_CPG_NONE, RCAR_CPG_KHZ(16660)),
};

/* NOTE: the array MUST be sorted by module field */
static struct cpg_clk_info_table mod_props[] = {
	RCAR_MOD_CLK_INFO_ITEM(702, R8A779F0_CLK_S0D12_PER),
	RCAR_MOD_CLK_INFO_ITEM(704, R8A779F0_CLK_S0D12_PER),

	RCAR_MOD_CLK_INFO_ITEM(915, R8A779F0_CLK_CL16M),
};

static int r8a779f0_cpg_enable_disable_core(const struct device *dev,
					   struct cpg_clk_info_table *clk_info,
					   uint32_t enable)
{
	int ret = -ENOTSUP;
	uint32_t reg;

	enable = !!enable;

	/* Not any used clocks needs to be manually endisable for now */
	switch (clk_info->module) {
	default:
		break;
	}

	if (!ret) {
		rcar_cpg_write(DEVICE_MMIO_GET(dev), clk_info->offset, reg);
	}
	return ret;
}

static int r8a779f0_cpg_core_clock_endisable(const struct device *dev,
					    struct rcar_cpg_clk *clk,
					    bool enable)
{
	struct cpg_clk_info_table *clk_info;
	struct r8a779f0_cpg_mssr_data *data = dev->data;
	k_spinlock_key_t key;
	int ret = 0;

	clk_info = rcar_cpg_find_clk_info_by_module_id(dev, clk->domain, clk->module);
	if (!clk_info) {
		return -EINVAL;
	}

	if (enable) {
		if (clk->rate > 0) {
			uintptr_t rate = clk->rate;

			ret = rcar_cpg_set_rate(dev, (clock_control_subsys_t)clk,
						(clock_control_subsys_rate_t)rate);
			if (ret < 0) {
				return ret;
			}
		}
	}

	key = k_spin_lock(&data->cmn.lock);
	r8a779f0_cpg_enable_disable_core(dev, clk_info, enable);
	k_spin_unlock(&data->cmn.lock, key);

	return ret;
}

int r8a779f0_cpg_mssr_start_stop(const struct device *dev,
	clock_control_subsys_t sys, bool enable)
{
	struct rcar_cpg_clk *clk = (struct rcar_cpg_clk *)sys;
	int ret = -EINVAL;

	if (!dev || !sys) {
		return -EINVAL;
	}

	if (clk->domain == CPG_MOD) {
		struct r8a779f0_cpg_mssr_data *data = dev->data;
		k_spinlock_key_t key;

		key = k_spin_lock(&data->cmn.lock);
		ret = rcar_cpg_mstp_clock_endisable(DEVICE_MMIO_GET(dev), clk->module, enable);
		k_spin_unlock(&data->cmn.lock, key);
	} else if (clk->domain == CPG_CORE) {
		ret = r8a779f0_cpg_core_clock_endisable(dev, clk, enable);
	}

	return ret;
}

static uint32_t r8a779f0_get_div_helper(uint32_t reg_val, uint32_t module)
{
	uint32_t divider = RCAR_CPG_NONE;

	switch (module) {
	case R8A779F0_CLK_S0D12_PER:
	case R8A779F0_CLK_CL16M:
		divider = 1;
		break;
	default:
		break;
	}

	return divider;
}

static int r8a779f0_set_rate_helper(uint32_t module, uint32_t *divider, uint32_t *div_mask)
{
	int ret = -ENOTSUP;

	/* Not any used clocks has a manually setable rate for now */
	switch (module) {
	default:
		break;
	}

	return ret;
}

static int r8a779f0_cpg_mssr_start(const struct device *dev,
				  clock_control_subsys_t sys)
{
	return r8a779f0_cpg_mssr_start_stop(dev, sys, true);
}

static int r8a779f0_cpg_mssr_stop(const struct device *dev,
				 clock_control_subsys_t sys)
{
	return r8a779f0_cpg_mssr_start_stop(dev, sys, false);
}

static int r8a779f0_cpg_mssr_init(const struct device *dev)
{
	DEVICE_MMIO_MAP(dev, K_MEM_CACHE_NONE);

	rcar_cpg_build_clock_relationship(dev);
	rcar_cpg_update_all_in_out_freq(dev);
	return 0;
}

static const struct clock_control_driver_api r8a779f0_cpg_mssr_api = {
	.on = r8a779f0_cpg_mssr_start,
	.off = r8a779f0_cpg_mssr_stop,
	.get_rate = rcar_cpg_get_rate,
	.set_rate = rcar_cpg_set_rate,
};

#define R8A779F0_MSSR_INIT(inst)							\
	static struct r8a779f0_cpg_mssr_cfg cpg_mssr##inst##_cfg = {		\
		DEVICE_MMIO_ROM_INIT(DT_DRV_INST(inst)),			\
	};									\
										\
	static struct r8a779f0_cpg_mssr_data cpg_mssr##inst##_data = {		\
		.cmn.clk_info_table[CPG_CORE] = core_props,			\
		.cmn.clk_info_table_size[CPG_CORE] = ARRAY_SIZE(core_props),	\
		.cmn.clk_info_table[CPG_MOD] = mod_props,			\
		.cmn.clk_info_table_size[CPG_MOD] = ARRAY_SIZE(mod_props),	\
		.cmn.get_div_helper = r8a779f0_get_div_helper,			\
		.cmn.set_rate_helper = r8a779f0_set_rate_helper			\
	};									\
										\
	DEVICE_DT_INST_DEFINE(inst,						\
			      &r8a779f0_cpg_mssr_init,				\
			      NULL,						\
			      &cpg_mssr##inst##_data,				\
			      &cpg_mssr##inst##_cfg,				\
			      PRE_KERNEL_1,					\
			      CONFIG_CLOCK_CONTROL_INIT_PRIORITY,		\
			      &r8a779f0_cpg_mssr_api);

DT_INST_FOREACH_STATUS_OKAY(R8A779F0_MSSR_INIT)
