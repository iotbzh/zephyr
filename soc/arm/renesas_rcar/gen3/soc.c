/*
 * Copyright (c) 2021 IoT.bzh
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#include <kernel.h>
#include <device.h>
#include <init.h>
#include <arch/arm/aarch32/mpu/arm_mpu.h>

#define MPUTYPE_READ_ONLY		{ .rasr = (P_RO_U_RO_Msk   | (7 << MPU_RASR_TEX_Pos) | MPU_RASR_C_Msk | MPU_RASR_B_Msk | MPU_RASR_XN_Msk) }
#define MPUTYPE_READ_AND_EXEC    	{ .rasr = (P_RO_U_RO_Msk   | (7 << MPU_RASR_TEX_Pos) | MPU_RASR_C_Msk | MPU_RASR_B_Msk)                   }
#define MPUTYPE_WBWACACHE		{ .rasr = (P_RW_U_RO_Msk   | (5 << MPU_RASR_TEX_Pos) |                  MPU_RASR_B_Msk)                   }
#define MPUTYPE_PRIV_DEVICE		{ .rasr = (P_RW_U_NA_Msk   | (2 << MPU_RASR_TEX_Pos))                                                     }
#define MPUTYPE_DEVICE			{ .rasr = (FULL_ACCESS_Msk | (2 << MPU_RASR_TEX_Pos))                                                     }
#define MPUTYPE_NO_ACCESS		{ .rasr = (NO_ACCESS_Msk) }

#define MPUTYPE_FULL { .rasr = (FULL_ACCESS_Msk   | (7 << MPU_RASR_TEX_Pos) | MPU_RASR_C_Msk | MPU_RASR_B_Msk)                   }

static const struct arm_mpu_region mpu_regions[] = {
	MPU_REGION_ENTRY("Default",
			 0x00000000,
			 REGION_4G,
			 MPUTYPE_FULL),
	MPU_REGION_ENTRY("PERIPHERALS",
			 0xC0000000,
			 REGION_1G,
			 MPUTYPE_DEVICE),

	MPU_REGION_ENTRY("SRAM_1",
			  0x40000000,
			 REGION_1G,
			 MPUTYPE_FULL),
};

const struct arm_mpu_config mpu_config = {
	.num_regions = ARRAY_SIZE(mpu_regions),
	.mpu_regions = mpu_regions,
};

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
	__set_ICIALLU(0);
	__DSB();
	__ISB();

	L1C_EnableCaches();
	L1C_EnableBTAC();
}

SYS_INIT(soc_init, PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
