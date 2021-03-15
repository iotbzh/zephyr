/*
 * Copyright (c) 2020 IoT.bzh
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#include <kernel.h>
#include <device.h>
#include <init.h>
#include <arch/arm/aarch32/cortex_a_r/cmsis.h>

/**
 *
 * @brief Perform basic hardware initialization
 *
 * @return 0
 */

static int soc_init(const struct device *arg)
{
	ARG_UNUSED(arg);

	/* Install default handler that simply resets the CPU
	 * if configured in the kernel, NOP otherwise
	 */
	NMI_INIT();
	return 0;
}

void z_platform_init(void)
{
	L1C_DisableCaches();
	L1C_DisableBTAC();

	/* Invalidate instruction cache and flush branch target cache */
	L1C_InvalidateICacheAll();
	L1C_InvalidateDCacheAll();
	L1C_InvalidateBTAC();

	L1C_EnableCaches();
	L1C_EnableBTAC();
}

SYS_INIT(soc_init, PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
