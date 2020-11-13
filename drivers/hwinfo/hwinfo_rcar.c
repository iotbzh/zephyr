/*
 * Copyright (c) 2020 IoT.BzH
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <soc.h>
#include <drivers/hwinfo.h>
#include <string.h>
#include <sys/byteorder.h>


/* Product Register */
#define PRR			0xFFF00044U
#define PRR_PRODUCT_MASK	0x00007F00U
#define PRR_CUT_MASK		0x000000FFU
#define PRR_PRODUCT_H3		0x00004F00U	/* R-Car H3 and H3-N */
#define PRR_PRODUCT_M3		0x00005200U	/* R-Car M3-W and M3-W+ */
#define PRR_PRODUCT_V3M		0x00005400U	/* R-Car V3M */
#define PRR_PRODUCT_V3H		0x00005600U	/* R-Car V3H */
#define PRR_PRODUCT_D3		0x00005800U	/* R-Car D3 */
#define PRR_PRODUCT_M3N		0x00005500U	/* R-Car M3-N */
#define PRR_PRODUCT_E3		0x00005700U	/* R-Car E3 */

static RCAR_DEV_NAME_T rcar_device = RCAR_LSI_UNKNOWN_DEVICE;

static void PRR_ReadDevice(void)
{
	RCAR_DEV_NAME_T dev;
	uint32_t prr;
	uint32_t product;
	int count;

	prr = sys_read32(PRR);
	product = prr & PRR_PRODUCT_MASK;

	switch (product) {
	case PRR_PRODUCT_H3:
		dev = RCAR_LSI_H3;
		break;
	case PRR_PRODUCT_M3:
		dev = RCAR_LSI_M3W;
		break;
	case PRR_PRODUCT_V3M:
		dev = RCAR_LSI_V3M;
		break;
	case PRR_PRODUCT_V3H:
		dev = RCAR_LSI_V3H;
		break;
	case PRR_PRODUCT_D3:
		dev = RCAR_LSI_D3;
		break;
	case PRR_PRODUCT_M3N:
		dev = RCAR_LSI_M3N;
		break;
	case PRR_PRODUCT_E3:
		dev = RCAR_LSI_E3;
		break;
	default:
		dev = RCAR_LSI_UNKNOWN_DEVICE;
		break;
	}
	rcar_device = dev;
}

ssize_t z_impl_hwinfo_get_device_id(uint8_t *buffer, size_t length)
{
    if (rcar_device == RCAR_LSI_UNKNOWN_DEVICE)
		PRR_ReadDevice();

    memcpy(buffer, &rcar_device, sizeof(rcar_device));
	return sizeof(rcar_device);
}
