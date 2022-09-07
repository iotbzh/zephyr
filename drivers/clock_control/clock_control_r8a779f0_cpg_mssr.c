/*
 * Copyright (c) 2022 IoT.bzh
 *
 * r8a779f0 Clock Pulse Generator / Module Standby and Software Reset
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT renesas_r8a779f0_cpg_mssr

#include <errno.h>
#include <soc.h>
#include <zephyr/drivers/clock_control.h>
#include <zephyr/drivers/clock_control/renesas_cpg_mssr.h>
#include <zephyr/dt-bindings/clock/renesas_cpg_mssr.h>
#include <zephyr/dt-bindings/clock/r8a779f0_cpg_mssr.h>
#include <zephyr/irq.h>
#include "clock_control_renesas_cpg_mssr.h"

#define LOG_LEVEL CONFIG_CLOCK_CONTROL_LOG_LEVEL
#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(clock_control_rcar);

struct r8a779f0_cpg_mssr_config {
	mm_reg_t base_address;
};

int r8a779f0_cpg_mssr_start_stop(const struct device *dev,
				clock_control_subsys_t sys, bool enable)
{
	const struct r8a779f0_cpg_mssr_config *config = dev->config;
	struct rcar_cpg_clk *clk = (struct rcar_cpg_clk *)sys;
	int ret = -EINVAL;

	if (clk->domain == CPG_MOD) {
		ret = rcar_cpg_mstp_clock_endisable(config->base_address, clk->module, enable);
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

static int r8a779f0_cpg_get_rate(const struct device *dev,
				clock_control_subsys_t sys,
				uint32_t *rate)
{
	struct rcar_cpg_clk *clk = (struct rcar_cpg_clk *)sys;
	int ret = 0;

	if (clk->domain != CPG_CORE) {
		return -ENOTSUP;
	}

	switch (clk->module) {
	case R8A779F0_CLK_S0D12_PER:
		*rate = S0D12_PER_CLK_RATE;
		break;
	default:
		ret = -ENOTSUP;
		break;
	}

	return ret;
}

static int r8a779f0_cpg_mssr_init(const struct device *dev)
{
	ARG_UNUSED(dev);
	return 0;
}

static const struct clock_control_driver_api r8a779f0_cpg_mssr_api = {
	.on = r8a779f0_cpg_mssr_start,
	.off = r8a779f0_cpg_mssr_stop,
	.get_rate = r8a779f0_cpg_get_rate,
};

#define R8A779f0_MSSR_INIT(inst)							  \
	static struct r8a779f0_cpg_mssr_config r8a779f0_cpg_mssr##inst##_config = { \
		.base_address = DT_INST_REG_ADDR(inst)				  \
	};									  \
										  \
	DEVICE_DT_INST_DEFINE(inst,						  \
			      &r8a779f0_cpg_mssr_init,				  \
			      NULL,						  \
			      NULL, &r8a779f0_cpg_mssr##inst##_config,		  \
			      PRE_KERNEL_1,					  \
			      CONFIG_CLOCK_CONTROL_INIT_PRIORITY,		  \
			      &r8a779f0_cpg_mssr_api);

DT_INST_FOREACH_STATUS_OKAY(R8A779f0_MSSR_INIT)
