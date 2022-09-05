/*
 * Copyright (c) 2022 IoT.bzh
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#include <errno.h>
#include "pinctrl_soc.h"
#include <zephyr/dt-bindings/pinctrl/renesas/pinctrl-r8a779a0.h>

const struct pfc_drive_reg pfc_drive_regs[] = {
	/* DRV0CTRL0 */
	{ 0x80, {
		{ RCAR_GP_PIN(0,  7), 28, 2 },	/* QSPI1_MOSI_IO0 */
		{ RCAR_GP_PIN(0,  6), 24, 2 },	/* QSPI1_SPCLK */
		{ RCAR_GP_PIN(0,  5), 20, 2 },	/* QSPI0_SSL */
		{ RCAR_GP_PIN(0,  4), 16, 2 },	/* QSPI0_IO3 */
		{ RCAR_GP_PIN(0,  3), 12, 2 },	/* QSPI0_IO2 */
		{ RCAR_GP_PIN(0,  2),  8, 2 },	/* QSPI0_MISO_IO1 */
		{ RCAR_GP_PIN(0,  1),  4, 2 },	/* QSPI0_MOSI_IO0 */
		{ RCAR_GP_PIN(0,  0),  0, 2 },	/* QSPI0_SPCLK */
	} },
	/* DRV1CTRL0 */
	{ 0x84, {
		{ RCAR_GP_PIN(0, 15), 28, 3 },	/* SD_WP */
		{ RCAR_GP_PIN(0, 14), 24, 2 },	/* RPC_INT_N */
		{ RCAR_GP_PIN(0, 13), 20, 2 },	/* RPC_WP_N */
		{ RCAR_GP_PIN(0, 12), 16, 2 },	/* RPC_RESET_N */
		{ RCAR_GP_PIN(0, 11), 12, 2 },	/* QSPI1_SSL */
		{ RCAR_GP_PIN(0, 10),  8, 2 },	/* QSPI1_IO3 */
		{ RCAR_GP_PIN(0,  9),  4, 2 },	/* QSPI1_IO2 */
		{ RCAR_GP_PIN(0,  8),  0, 2 },	/* QSPI1_MISO_IO1 */
	} },
	/* DRV2CTRL0 */
	{ 0x88, {
		{ RCAR_GP_PIN(0, 23), 28, 3 },	/* MMC_SD_CLK */
		{ RCAR_GP_PIN(0, 22), 24, 3 },	/* MMC_SD_D3 */
		{ RCAR_GP_PIN(0, 21), 20, 3 },	/* MMC_SD_D2 */
		{ RCAR_GP_PIN(0, 20), 16, 3 },	/* MMC_SD_D1 */
		{ RCAR_GP_PIN(0, 19), 12, 3 },	/* MMC_SD_D0 */
		{ RCAR_GP_PIN(0, 18),  8, 3 },	/* MMC_SD_CMD */
		{ RCAR_GP_PIN(0, 17),  4, 3 },	/* MMC_DS */
		{ RCAR_GP_PIN(0, 16),  0, 3 },	/* SD_CD */
	} },
	/* DRV3CTRL0 */
	{ 0x8c, {
		{ RCAR_GP_PIN(0, 27), 12, 3 },	/* MMC_D7 */
		{ RCAR_GP_PIN(0, 26),  8, 3 },	/* MMC_D6 */
		{ RCAR_GP_PIN(0, 25),  4, 3 },	/* MMC_D5 */
		{ RCAR_GP_PIN(0, 24),  0, 3 },	/* MMC_D4 */
	} },
	/* DRV0CTRL1 */
	{ 0x80, {
		{ RCAR_GP_PIN(1,  7), 28, 3 },	/* MSIOF0_TXD */
		{ RCAR_GP_PIN(1,  6), 24, 3 },	/* MSIOF0_RXD */
		{ RCAR_GP_PIN(1,  5), 20, 3 },	/* HTX0 */
		{ RCAR_GP_PIN(1,  4), 16, 3 },	/* HCTS0_N */
		{ RCAR_GP_PIN(1,  3), 12, 3 },	/* HRTS0_N */
		{ RCAR_GP_PIN(1,  2),  8, 3 },	/* HSCK0 */
		{ RCAR_GP_PIN(1,  1),  4, 3 },	/* HRX0 */
		{ RCAR_GP_PIN(1,  0),  0, 3 },	/* SCIF_CLK */
	} },
	/* DRV1CTRL1 */
	{ 0x84, {
		{ RCAR_GP_PIN(1, 15), 28, 3 },	/* MSIOF1_SYNC */
		{ RCAR_GP_PIN(1, 14), 24, 3 },	/* MSIOF1_SCK */
		{ RCAR_GP_PIN(1, 13), 20, 3 },	/* MSIOF1_TXD */
		{ RCAR_GP_PIN(1, 12), 16, 3 },	/* MSIOF1_RXD */
		{ RCAR_GP_PIN(1, 11), 12, 3 },	/* MSIOF0_SS2 */
		{ RCAR_GP_PIN(1, 10),  8, 3 },	/* MSIOF0_SS1 */
		{ RCAR_GP_PIN(1,  9),  4, 3 },	/* MSIOF0_SYNC */
		{ RCAR_GP_PIN(1,  8),  0, 3 },	/* MSIOF0_SCK */
	} },
	/* DRV2CTRL1 */
	{ 0x88, {
		{ RCAR_GP_PIN(1, 23), 28, 3 },	/* MSIOF2_SS2 */
		{ RCAR_GP_PIN(1, 22), 24, 3 },	/* MSIOF2_SS1 */
		{ RCAR_GP_PIN(1, 21), 20, 3 },	/* MSIOF2_SYNC */
		{ RCAR_GP_PIN(1, 20), 16, 3 },	/* MSIOF2_SCK */
		{ RCAR_GP_PIN(1, 19), 12, 3 },	/* MSIOF2_TXD */
		{ RCAR_GP_PIN(1, 18),  8, 3 },	/* MSIOF2_RXD */
		{ RCAR_GP_PIN(1, 17),  4, 3 },	/* MSIOF1_SS2 */
		{ RCAR_GP_PIN(1, 16),  0, 3 },	/* MSIOF1_SS1 */
	} },
	/* DRV3CTRL1 */
	{ 0x8c, {
		{ RCAR_GP_PIN(1, 30), 24, 3 },	/* GP1_30 */
		{ RCAR_GP_PIN(1, 29), 20, 3 },	/* GP1_29 */
		{ RCAR_GP_PIN(1, 28), 16, 3 },	/* GP1_28 */
		{ RCAR_GP_PIN(1, 27), 12, 3 },	/* IRQ3 */
		{ RCAR_GP_PIN(1, 26),  8, 3 },	/* IRQ2 */
		{ RCAR_GP_PIN(1, 25),  4, 3 },	/* IRQ1 */
		{ RCAR_GP_PIN(1, 24),  0, 3 },	/* IRQ0 */
	} },
	/* DRV0CTRL2 */
	{ 0x80, {
		{ RCAR_GP_PIN(2,  7), 28, 3 },	/* GP2_07 */
		{ RCAR_GP_PIN(2,  6), 24, 3 },	/* GP2_06 */
		{ RCAR_GP_PIN(2,  5), 20, 3 },	/* GP2_05 */
		{ RCAR_GP_PIN(2,  4), 16, 3 },	/* GP2_04 */
		{ RCAR_GP_PIN(2,  3), 12, 3 },	/* GP2_03 */
		{ RCAR_GP_PIN(2,  2),  8, 3 },	/* GP2_02 */
		{ RCAR_GP_PIN(2,  1),  4, 2 },	/* IPC_CLKOUT */
		{ RCAR_GP_PIN(2,  0),  0, 2 },	/* IPC_CLKIN */
	} },
	/* DRV1CTRL2 */
	{ 0x84, {
		{ RCAR_GP_PIN(2, 15), 28, 3 },	/* GP2_15 */
		{ RCAR_GP_PIN(2, 14), 24, 3 },	/* GP2_14 */
		{ RCAR_GP_PIN(2, 13), 20, 3 },	/* GP2_13 */
		{ RCAR_GP_PIN(2, 12), 16, 3 },	/* GP2_12 */
		{ RCAR_GP_PIN(2, 11), 12, 3 },	/* GP2_11 */
		{ RCAR_GP_PIN(2, 10),  8, 3 },	/* GP2_10 */
		{ RCAR_GP_PIN(2,  9),  4, 3 },	/* GP2_9 */
		{ RCAR_GP_PIN(2,  8),  0, 3 },	/* GP2_8 */
	} },
	/* DRV2CTRL2 */
	{ 0x88, {
		{ RCAR_GP_PIN(2, 23), 28, 3 },	/* TCLK1_A */
		{ RCAR_GP_PIN(2, 22), 24, 3 },	/* TPU0TO1 */
		{ RCAR_GP_PIN(2, 21), 20, 3 },	/* TPU0TO0 */
		{ RCAR_GP_PIN(2, 20), 16, 3 },	/* CLK_EXTFXR */
		{ RCAR_GP_PIN(2, 19), 12, 3 },	/* RXDB_EXTFXR */
		{ RCAR_GP_PIN(2, 18),  8, 3 },	/* FXR_TXDB */
		{ RCAR_GP_PIN(2, 17),  4, 3 },	/* RXDA_EXTFXR_A */
		{ RCAR_GP_PIN(2, 16),  0, 3 },	/* FXR_TXDA_A */
	} },
	/* DRV3CTRL2 */
	{ 0x8c, {
		{ RCAR_GP_PIN(2, 24), 0, 3 },	/* TCLK2_A */
	} },
	/* DRV0CTRL3 */
	{ 0x80, {
		{ RCAR_GP_PIN(3,  7), 28, 3 },	/* CANFD3_TX */
		{ RCAR_GP_PIN(3,  6), 24, 3 },	/* CANFD2_RX */
		{ RCAR_GP_PIN(3,  5), 20, 3 },	/* CANFD2_TX */
		{ RCAR_GP_PIN(3,  4), 16, 3 },	/* CANFD1_RX */
		{ RCAR_GP_PIN(3,  3), 12, 3 },	/* CANFD1_TX */
		{ RCAR_GP_PIN(3,  2),  8, 3 },	/* CANFD0_RX */
		{ RCAR_GP_PIN(3,  1),  4, 2 },	/* CANFD0_TX */
		{ RCAR_GP_PIN(3,  0),  0, 2 },	/* CAN_CLK */
	} },
	/* DRV1CTRL3 */
	{ 0x84, {
		{ RCAR_GP_PIN(3, 15), 28, 3 },	/* CANFD7_TX */
		{ RCAR_GP_PIN(3, 14), 24, 3 },	/* CANFD6_RX */
		{ RCAR_GP_PIN(3, 13), 20, 3 },	/* CANFD6_TX */
		{ RCAR_GP_PIN(3, 12), 16, 3 },	/* CANFD5_RX */
		{ RCAR_GP_PIN(3, 11), 12, 3 },	/* CANFD5_TX */
		{ RCAR_GP_PIN(3, 10),  8, 3 },	/* CANFD4_RX */
		{ RCAR_GP_PIN(3,  9),  4, 3 },	/* CANFD4_TX */
		{ RCAR_GP_PIN(3,  8),  0, 3 },	/* CANFD3_RX */
	} },
	/* DRV2CTRL3 */
	{ 0x88, {
		{ RCAR_GP_PIN(3,  16),  0, 3 },	/* CANFD7_RX */
	} },
	/* DRV0CTRL4 */
	{ 0x80, {
		{ RCAR_GP_PIN(4,  7), 28, 3 },	/* AVB0_TXC */
		{ RCAR_GP_PIN(4,  6), 24, 3 },	/* AVB0_TX_CTL */
		{ RCAR_GP_PIN(4,  5), 20, 3 },	/* AVB0_RD3 */
		{ RCAR_GP_PIN(4,  4), 16, 3 },	/* AVB0_RD2 */
		{ RCAR_GP_PIN(4,  3), 12, 3 },	/* AVB0_RD1 */
		{ RCAR_GP_PIN(4,  2),  8, 3 },	/* AVB0_RD0 */
		{ RCAR_GP_PIN(4,  1),  4, 3 },	/* AVB0_RXC */
		{ RCAR_GP_PIN(4,  0),  0, 3 },	/* AVB0_RX_CTL */
	} },
	/* DRV1CTRL4 */
	{ 0x84, {
		{ RCAR_GP_PIN(4, 15), 28, 3 },	/* AVB0_MAGIC */
		{ RCAR_GP_PIN(4, 14), 24, 3 },	/* AVB0_MDC */
		{ RCAR_GP_PIN(4, 13), 20, 3 },	/* AVB0_MDIO */
		{ RCAR_GP_PIN(4, 12), 16, 3 },	/* AVB0_TXCREFCLK */
		{ RCAR_GP_PIN(4, 11), 12, 3 },	/* AVB0_TD3 */
		{ RCAR_GP_PIN(4, 10),  8, 3 },	/* AVB0_TD2 */
		{ RCAR_GP_PIN(4,  9),  4, 3 },	/* AVB0_TD1*/
		{ RCAR_GP_PIN(4,  8),  0, 3 },	/* AVB0_TD0 */
	} },
	/* DRV2CTRL4 */
	{ 0x88, {
		{ RCAR_GP_PIN(4, 23), 28, 3 },	/* PCIE2_CLKREQ_N */
		{ RCAR_GP_PIN(4, 22), 24, 3 },	/* PCIE1_CLKREQ_N */
		{ RCAR_GP_PIN(4, 21), 20, 3 },	/* PCIE0_CLKREQ_N */
		{ RCAR_GP_PIN(4, 20), 16, 3 },	/* AVB0_AVTP_PPS */
		{ RCAR_GP_PIN(4, 19), 12, 3 },	/* AVB0_AVTP_CAPTURE */
		{ RCAR_GP_PIN(4, 18),  8, 3 },	/* AVB0_AVTP_MATCH */
		{ RCAR_GP_PIN(4, 17),  4, 3 },	/* AVB0_LINK */
		{ RCAR_GP_PIN(4, 16),  0, 3 },	/* AVB0_PHY_INT */
	} },
	/* DRV3CTRL4 */
	{ 0x8c, {
		{ RCAR_GP_PIN(4, 26),  8, 3 },	/* AVS1 */
		{ RCAR_GP_PIN(4, 25),  4, 3 },	/* AVS0 */
		{ RCAR_GP_PIN(4, 24),  0, 3 },	/* PCIE3_CLKREQ_N */
	} },
	/* DRV0CTRL5 */
	{ 0x80, {
		{ RCAR_GP_PIN(5,  7), 28, 3 },	/* AVB1_TXC */
		{ RCAR_GP_PIN(5,  6), 24, 3 },	/* AVB1_TX_CTL */
		{ RCAR_GP_PIN(5,  5), 20, 3 },	/* AVB1_RD3 */
		{ RCAR_GP_PIN(5,  4), 16, 3 },	/* AVB1_RD2 */
		{ RCAR_GP_PIN(5,  3), 12, 3 },	/* AVB1_RD1 */
		{ RCAR_GP_PIN(5,  2),  8, 3 },	/* AVB1_RD0 */
		{ RCAR_GP_PIN(5,  1),  4, 3 },	/* AVB1_RXC */
		{ RCAR_GP_PIN(5,  0),  0, 3 },	/* AVB1_RX_CTL */
	} },
	/* DRV1CTRL5 */
	{ 0x84, {
		{ RCAR_GP_PIN(5, 15), 28, 3 },	/* AVB1_MAGIC */
		{ RCAR_GP_PIN(5, 14), 24, 3 },	/* AVB1_MDC */
		{ RCAR_GP_PIN(5, 13), 20, 3 },	/* AVB1_MDIO */
		{ RCAR_GP_PIN(5, 12), 16, 3 },	/* AVB1_TXCREFCLK */
		{ RCAR_GP_PIN(5, 11), 12, 3 },	/* AVB1_TD3 */
		{ RCAR_GP_PIN(5, 10),  8, 3 },	/* AVB1_TD2 */
		{ RCAR_GP_PIN(5,  9),  4, 3 },	/* AVB1_TD1*/
		{ RCAR_GP_PIN(5,  8),  0, 3 },	/* AVB1_TD0 */
	} },
	/* DRV2CTRL5 */
	{ 0x88, {
		{ RCAR_GP_PIN(5, 20), 16, 3 },	/* AVB1_AVTP_PPS */
		{ RCAR_GP_PIN(5, 19), 12, 3 },	/* AVB1_AVTP_CAPTURE */
		{ RCAR_GP_PIN(5, 18),  8, 3 },	/* AVB1_AVTP_MATCH */
		{ RCAR_GP_PIN(5, 17),  4, 3 },	/* AVB1_LINK */
		{ RCAR_GP_PIN(5, 16),  0, 3 },	/* AVB1_PHY_INT */
	} },
	/* DRV0CTRL6 */
	{ 0x80, {
		{ RCAR_GP_PIN(6,  7), 28, 3 },	/* AVB2_TXC */
		{ RCAR_GP_PIN(6,  6), 24, 3 },	/* AVB2_TX_CTL */
		{ RCAR_GP_PIN(6,  5), 20, 3 },	/* AVB2_RD3 */
		{ RCAR_GP_PIN(6,  4), 16, 3 },	/* AVB2_RD2 */
		{ RCAR_GP_PIN(6,  3), 12, 3 },	/* AVB2_RD1 */
		{ RCAR_GP_PIN(6,  2),  8, 3 },	/* AVB2_RD0 */
		{ RCAR_GP_PIN(6,  1),  4, 3 },	/* AVB2_RXC */
		{ RCAR_GP_PIN(6,  0),  0, 3 },	/* AVB2_RX_CTL */
	} },
	/* DRV1CTRL6 */
	{ 0x84, {
		{ RCAR_GP_PIN(6, 15), 28, 3 },	/* AVB2_MAGIC */
		{ RCAR_GP_PIN(6, 14), 24, 3 },	/* AVB2_MDC */
		{ RCAR_GP_PIN(6, 13), 20, 3 },	/* AVB2_MDIO */
		{ RCAR_GP_PIN(6, 12), 16, 3 },	/* AVB2_TXCREFCLK */
		{ RCAR_GP_PIN(6, 11), 12, 3 },	/* AVB2_TD3 */
		{ RCAR_GP_PIN(6, 10),  8, 3 },	/* AVB2_TD2 */
		{ RCAR_GP_PIN(6,  9),  4, 3 },	/* AVB2_TD1*/
		{ RCAR_GP_PIN(6,  8),  0, 3 },	/* AVB2_TD0 */
	} },
	/* DRV2CTRL6 */
	{ 0x88, {
		{ RCAR_GP_PIN(6, 20), 16, 3 },	/* AVB2_AVTP_PPS */
		{ RCAR_GP_PIN(6, 19), 12, 3 },	/* AVB2_AVTP_CAPTURE */
		{ RCAR_GP_PIN(6, 18),  8, 3 },	/* AVB2_AVTP_MATCH */
		{ RCAR_GP_PIN(6, 17),  4, 3 },	/* AVB2_LINK */
		{ RCAR_GP_PIN(6, 16),  0, 3 },	/* AVB2_PHY_INT */
	} },
	/* DRV0CTRL7 */
	{ 0x80, {
		{ RCAR_GP_PIN(7,  7), 28, 3 },	/* AVB3_TXC */
		{ RCAR_GP_PIN(7,  6), 24, 3 },	/* AVB3_TX_CTL */
		{ RCAR_GP_PIN(7,  5), 20, 3 },	/* AVB3_RD3 */
		{ RCAR_GP_PIN(7,  4), 16, 3 },	/* AVB3_RD2 */
		{ RCAR_GP_PIN(7,  3), 12, 3 },	/* AVB3_RD1 */
		{ RCAR_GP_PIN(7,  2),  8, 3 },	/* AVB3_RD0 */
		{ RCAR_GP_PIN(7,  1),  4, 3 },	/* AVB3_RXC */
		{ RCAR_GP_PIN(7,  0),  0, 3 },	/* AVB3_RX_CTL */
	} },
	/* DRV1CTRL7 */
	{ 0x84, {
		{ RCAR_GP_PIN(7, 15), 28, 3 },	/* AVB3_MAGIC */
		{ RCAR_GP_PIN(7, 14), 24, 3 },	/* AVB3_MDC */
		{ RCAR_GP_PIN(7, 13), 20, 3 },	/* AVB3_MDIO */
		{ RCAR_GP_PIN(7, 12), 16, 3 },	/* AVB3_TXCREFCLK */
		{ RCAR_GP_PIN(7, 11), 12, 3 },	/* AVB3_TD3 */
		{ RCAR_GP_PIN(7, 10),  8, 3 },	/* AVB3_TD2 */
		{ RCAR_GP_PIN(7,  9),  4, 3 },	/* AVB3_TD1*/
		{ RCAR_GP_PIN(7,  8),  0, 3 },	/* AVB3_TD0 */
	} },
	/* DRV2CTRL7 */
	{ 0x88, {
		{ RCAR_GP_PIN(7, 20), 16, 3 },	/* AVB3_AVTP_PPS */
		{ RCAR_GP_PIN(7, 19), 12, 3 },	/* AVB3_AVTP_CAPTURE */
		{ RCAR_GP_PIN(7, 18),  8, 3 },	/* AVB3_AVTP_MATCH */
		{ RCAR_GP_PIN(7, 17),  4, 3 },	/* AVB3_LINK */
		{ RCAR_GP_PIN(7, 16),  0, 3 },	/* AVB3_PHY_INT */
	} },
	/* DRV0CTRL8 */
	{ 0x80, {
		{ RCAR_GP_PIN(8,  7), 28, 3 },	/* AVB4_TXC */
		{ RCAR_GP_PIN(8,  6), 24, 3 },	/* AVB4_TX_CTL */
		{ RCAR_GP_PIN(8,  5), 20, 3 },	/* AVB4_RD3 */
		{ RCAR_GP_PIN(8,  4), 16, 3 },	/* AVB4_RD2 */
		{ RCAR_GP_PIN(8,  3), 12, 3 },	/* AVB4_RD1 */
		{ RCAR_GP_PIN(8,  2),  8, 3 },	/* AVB4_RD0 */
		{ RCAR_GP_PIN(8,  1),  4, 3 },	/* AVB4_RXC */
		{ RCAR_GP_PIN(8,  0),  0, 3 },	/* AVB4_RX_CTL */
	} },
	/* DRV1CTRL8 */
	{ 0x84, {
		{ RCAR_GP_PIN(8, 15), 28, 3 },	/* AVB4_MAGIC */
		{ RCAR_GP_PIN(8, 14), 24, 3 },	/* AVB4_MDC */
		{ RCAR_GP_PIN(8, 13), 20, 3 },	/* AVB4_MDIO */
		{ RCAR_GP_PIN(8, 12), 16, 3 },	/* AVB4_TXCREFCLK */
		{ RCAR_GP_PIN(8, 11), 12, 3 },	/* AVB4_TD3 */
		{ RCAR_GP_PIN(8, 10),  8, 3 },	/* AVB4_TD2 */
		{ RCAR_GP_PIN(8,  9),  4, 3 },	/* AVB4_TD1*/
		{ RCAR_GP_PIN(8,  8),  0, 3 },	/* AVB4_TD0 */
	} },
	/* DRV2CTRL8 */
	{ 0x88, {
		{ RCAR_GP_PIN(8, 20), 16, 3 },	/* AVB4_AVTP_PPS */
		{ RCAR_GP_PIN(8, 19), 12, 3 },	/* AVB4_AVTP_CAPTURE */
		{ RCAR_GP_PIN(8, 18),  8, 3 },	/* AVB4_AVTP_MATCH */
		{ RCAR_GP_PIN(8, 17),  4, 3 },	/* AVB4_LINK */
		{ RCAR_GP_PIN(8, 16),  0, 3 },	/* AVB4_PHY_INT */
	} },
	/* DRV0CTRL9 */
	{ 0x80, {
		{ RCAR_GP_PIN(9,  7), 28, 3 },	/* AVB5_TXC */
		{ RCAR_GP_PIN(9,  6), 24, 3 },	/* AVB5_TX_CTL */
		{ RCAR_GP_PIN(9,  5), 20, 3 },	/* AVB5_RD3 */
		{ RCAR_GP_PIN(9,  4), 16, 3 },	/* AVB5_RD2 */
		{ RCAR_GP_PIN(9,  3), 12, 3 },	/* AVB5_RD1 */
		{ RCAR_GP_PIN(9,  2),  8, 3 },	/* AVB5_RD0 */
		{ RCAR_GP_PIN(9,  1),  4, 3 },	/* AVB5_RXC */
		{ RCAR_GP_PIN(9,  0),  0, 3 },	/* AVB5_RX_CTL */
	} },
	/* DRV1CTRL9 */
	{ 0x84, {
		{ RCAR_GP_PIN(9, 15), 28, 3 },	/* AVB5_MAGIC */
		{ RCAR_GP_PIN(9, 14), 24, 3 },	/* AVB5_MDC */
		{ RCAR_GP_PIN(9, 13), 20, 3 },	/* AVB5_MDIO */
		{ RCAR_GP_PIN(9, 12), 16, 3 },	/* AVB5_TXCREFCLK */
		{ RCAR_GP_PIN(9, 11), 12, 3 },	/* AVB5_TD3 */
		{ RCAR_GP_PIN(9, 10),  8, 3 },	/* AVB5_TD2 */
		{ RCAR_GP_PIN(9,  9),  4, 3 },	/* AVB5_TD1*/
		{ RCAR_GP_PIN(9,  8),  0, 3 },	/* AVB5_TD0 */
	} },
	/* DRV2CTRL9 */
	{ 0x88, {
		{ RCAR_GP_PIN(9, 20), 16, 3 },	/* AVB5_AVTP_PPS */
		{ RCAR_GP_PIN(9, 19), 12, 3 },	/* AVB5_AVTP_CAPTURE */
		{ RCAR_GP_PIN(9, 18),  8, 3 },	/* AVB5_AVTP_MATCH */
		{ RCAR_GP_PIN(9, 17),  4, 3 },	/* AVB5_LINK */
		{ RCAR_GP_PIN(9, 16),  0, 3 },	/* AVB5_PHY_INT */
	} },
	{ },
};

#define PFC_BIAS_REG(r1, r2) \
	.puen = r1,	     \
	.pud = r2,	     \
	.pins =

const struct pfc_bias_reg pfc_bias_regs[] = {
	{ PFC_BIAS_REG(0xc0, 0xe0) {         /* PUEN0, PUD0 */
		[ 0] = RCAR_GP_PIN(0,  0),	/* QSPI0_SPCLK */
		[ 1] = RCAR_GP_PIN(0,  1),	/* QSPI0_MOSI_IO0 */
		[ 2] = RCAR_GP_PIN(0,  2),	/* QSPI0_MISO_IO1 */
		[ 3] = RCAR_GP_PIN(0,  3),	/* QSPI0_IO2 */
		[ 4] = RCAR_GP_PIN(0,  4),	/* QSPI0_IO3 */
		[ 5] = RCAR_GP_PIN(0,  5),	/* QSPI0_SSL */
		[ 6] = RCAR_GP_PIN(0,  6),	/* QSPI1_SPCLK */
		[ 7] = RCAR_GP_PIN(0,  7),	/* QSPI1_MOSI_IO0 */
		[ 8] = RCAR_GP_PIN(0,  8),	/* QSPI1_MISO_IO1 */
		[ 9] = RCAR_GP_PIN(0,  9),	/* QSPI1_IO2 */
		[10] = RCAR_GP_PIN(0, 10),	/* QSPI1_IO3 */
		[11] = RCAR_GP_PIN(0, 11),	/* QSPI1_SSL */
		[12] = RCAR_GP_PIN(0, 12),	/* RPC_RESET_N */
		[13] = RCAR_GP_PIN(0, 13),	/* RPC_WP_N */
		[14] = RCAR_GP_PIN(0, 14),	/* RPC_INT_N */
		[15] = RCAR_GP_PIN(0, 15),	/* SD_WP */
		[16] = RCAR_GP_PIN(0, 16),	/* SD_CD */
		[17] = RCAR_GP_PIN(0, 17),	/* MMC_DS */
		[18] = RCAR_GP_PIN(0, 18),	/* MMC_SD_CMD */
		[19] = RCAR_GP_PIN(0, 19),	/* MMC_SD_D0 */
		[20] = RCAR_GP_PIN(0, 20),	/* MMC_SD_D1 */
		[21] = RCAR_GP_PIN(0, 21),	/* MMC_SD_D2 */
		[22] = RCAR_GP_PIN(0, 22),	/* MMC_SD_D3 */
		[23] = RCAR_GP_PIN(0, 23),	/* MMC_SD_CLK */
		[24] = RCAR_GP_PIN(0, 24),	/* MMC_D4 */
		[25] = RCAR_GP_PIN(0, 25),	/* MMC_D5 */
		[26] = RCAR_GP_PIN(0, 26),	/* MMC_D6 */
		[27] = RCAR_GP_PIN(0, 27),	/* MMC_D7 */
		[28] = PIN_NONE,
		[29] = PIN_NONE,
		[30] = PIN_NONE,
		[31] = PIN_NONE,
	} },
	{ PFC_BIAS_REG(0xc0, 0xe0) {         /* PUEN1, PUD1 */
		[ 0] = RCAR_GP_PIN(1,  0),	/* SCIF_CLK */
		[ 1] = RCAR_GP_PIN(1,  1),	/* HRX0 */
		[ 2] = RCAR_GP_PIN(1,  2),	/* HSCK0 */
		[ 3] = RCAR_GP_PIN(1,  3),	/* HRTS0_N */
		[ 4] = RCAR_GP_PIN(1,  4),	/* HCTS0_N */
		[ 5] = RCAR_GP_PIN(1,  5),	/* HTX0 */
		[ 6] = RCAR_GP_PIN(1,  6),	/* MSIOF0_RXD */
		[ 7] = RCAR_GP_PIN(1,  7),	/* MSIOF0_TXD */
		[ 8] = RCAR_GP_PIN(1,  8),	/* MSIOF0_SCK */
		[ 9] = RCAR_GP_PIN(1,  9),	/* MSIOF0_SYNC */
		[10] = RCAR_GP_PIN(1, 10),	/* MSIOF0_SS1 */
		[11] = RCAR_GP_PIN(1, 11),	/* MSIOF0_SS2 */
		[12] = RCAR_GP_PIN(1, 12),	/* MSIOF1_RXD */
		[13] = RCAR_GP_PIN(1, 13),	/* MSIOF1_TXD */
		[14] = RCAR_GP_PIN(1, 14),	/* MSIOF1_SCK */
		[15] = RCAR_GP_PIN(1, 15),	/* MSIOF1_SYNC */
		[16] = RCAR_GP_PIN(1, 16),	/* MSIOF1_SS1 */
		[17] = RCAR_GP_PIN(1, 17),	/* MSIOF1_SS2 */
		[18] = RCAR_GP_PIN(1, 18),	/* MSIOF2_RXD */
		[19] = RCAR_GP_PIN(1, 19),	/* MSIOF2_TXD */
		[20] = RCAR_GP_PIN(1, 20),	/* MSIOF2_SCK */
		[21] = RCAR_GP_PIN(1, 21),	/* MSIOF2_SYNC */
		[22] = RCAR_GP_PIN(1, 22),	/* MSIOF2_SS1 */
		[23] = RCAR_GP_PIN(1, 23),	/* MSIOF2_SS2 */
		[24] = RCAR_GP_PIN(1, 24),	/* IRQ0 */
		[25] = RCAR_GP_PIN(1, 25),	/* IRQ1 */
		[26] = RCAR_GP_PIN(1, 26),	/* IRQ2 */
		[27] = RCAR_GP_PIN(1, 27),	/* IRQ3 */
		[28] = RCAR_GP_PIN(1, 28),	/* GP1_28 */
		[29] = RCAR_GP_PIN(1, 29),	/* GP1_29 */
		[30] = RCAR_GP_PIN(1, 30),	/* GP1_30 */
		[31] = PIN_NONE,
	} },
	{ PFC_BIAS_REG(0xc0, 0xe0) {         /* PUEN2, PUD2 */
		[ 0] = RCAR_GP_PIN(2,  0),	/* IPC_CLKIN */
		[ 1] = RCAR_GP_PIN(2,  1),	/* IPC_CLKOUT */
		[ 2] = RCAR_GP_PIN(2,  2),	/* GP2_02 */
		[ 3] = RCAR_GP_PIN(2,  3),	/* GP2_03 */
		[ 4] = RCAR_GP_PIN(2,  4),	/* GP2_04 */
		[ 5] = RCAR_GP_PIN(2,  5),	/* GP2_05 */
		[ 6] = RCAR_GP_PIN(2,  6),	/* GP2_06 */
		[ 7] = RCAR_GP_PIN(2,  7),	/* GP2_07 */
		[ 8] = RCAR_GP_PIN(2,  8),	/* GP2_08 */
		[ 9] = RCAR_GP_PIN(2,  9),	/* GP2_09 */
		[10] = RCAR_GP_PIN(2, 10),	/* GP2_10 */
		[11] = RCAR_GP_PIN(2, 11),	/* GP2_11 */
		[12] = RCAR_GP_PIN(2, 12),	/* GP2_12 */
		[13] = RCAR_GP_PIN(2, 13),	/* GP2_13 */
		[14] = RCAR_GP_PIN(2, 14),	/* GP2_14 */
		[15] = RCAR_GP_PIN(2, 15),	/* GP2_15 */
		[16] = RCAR_GP_PIN(2, 16),	/* FXR_TXDA_A */
		[17] = RCAR_GP_PIN(2, 17),	/* RXDA_EXTFXR_A */
		[18] = RCAR_GP_PIN(2, 18),	/* FXR_TXDB */
		[19] = RCAR_GP_PIN(2, 19),	/* RXDB_EXTFXR */
		[20] = RCAR_GP_PIN(2, 20),	/* CLK_EXTFXR */
		[21] = RCAR_GP_PIN(2, 21),	/* TPU0TO0 */
		[22] = RCAR_GP_PIN(2, 22),	/* TPU0TO1 */
		[23] = RCAR_GP_PIN(2, 23),	/* TCLK1_A */
		[24] = RCAR_GP_PIN(2, 24),	/* TCLK2_A */
		[25] = PIN_NONE,
		[26] = PIN_NONE,
		[27] = PIN_NONE,
		[28] = PIN_NONE,
		[29] = PIN_NONE,
		[30] = PIN_NONE,
		[31] = PIN_NONE,
	} },
	{ PFC_BIAS_REG(0xc0, 0xe0) {         /* PUEN3, PUD3 */
		[ 0] = RCAR_GP_PIN(3,  0),	/* CAN_CLK */
		[ 1] = RCAR_GP_PIN(3,  1),	/* CANFD0_TX */
		[ 2] = RCAR_GP_PIN(3,  2),	/* CANFD0_RX */
		[ 3] = RCAR_GP_PIN(3,  3),	/* CANFD1_TX */
		[ 4] = RCAR_GP_PIN(3,  4),	/* CANFD1_RX */
		[ 5] = RCAR_GP_PIN(3,  5),	/* CANFD2_TX */
		[ 6] = RCAR_GP_PIN(3,  6),	/* CANFD2_RX */
		[ 7] = RCAR_GP_PIN(3,  7),	/* CANFD3_TX */
		[ 8] = RCAR_GP_PIN(3,  8),	/* CANFD3_RX */
		[ 9] = RCAR_GP_PIN(3,  9),	/* CANFD4_TX */
		[10] = RCAR_GP_PIN(3, 10),	/* CANFD4_RX */
		[11] = RCAR_GP_PIN(3, 11),	/* CANFD5_TX */
		[12] = RCAR_GP_PIN(3, 12),	/* CANFD5_RX */
		[13] = RCAR_GP_PIN(3, 13),	/* CANFD6_TX */
		[14] = RCAR_GP_PIN(3, 14),	/* CANFD6_RX */
		[15] = RCAR_GP_PIN(3, 15),	/* CANFD7_TX */
		[16] = RCAR_GP_PIN(3, 16),	/* CANFD7_RX */
		[17] = PIN_NONE,
		[18] = PIN_NONE,
		[19] = PIN_NONE,
		[20] = PIN_NONE,
		[21] = PIN_NONE,
		[22] = PIN_NONE,
		[23] = PIN_NONE,
		[24] = PIN_NONE,
		[25] = PIN_NONE,
		[26] = PIN_NONE,
		[27] = PIN_NONE,
		[28] = PIN_NONE,
		[29] = PIN_NONE,
		[30] = PIN_NONE,
		[31] = PIN_NONE,
	} },
	{ PFC_BIAS_REG(0xc0, 0xe0) {         /* PUEN4, PUD4 */
		[ 0] = RCAR_GP_PIN(4,  0),	/* AVB0_RX_CTL */
		[ 1] = RCAR_GP_PIN(4,  1),	/* AVB0_RXC */
		[ 2] = RCAR_GP_PIN(4,  2),	/* AVB0_RD0 */
		[ 3] = RCAR_GP_PIN(4,  3),	/* AVB0_RD1 */
		[ 4] = RCAR_GP_PIN(4,  4),	/* AVB0_RD2 */
		[ 5] = RCAR_GP_PIN(4,  5),	/* AVB0_RD3 */
		[ 6] = RCAR_GP_PIN(4,  6),	/* AVB0_TX_CTL */
		[ 7] = RCAR_GP_PIN(4,  7),	/* AVB0_TXC */
		[ 8] = RCAR_GP_PIN(4,  8),	/* AVB0_TD0 */
		[ 9] = RCAR_GP_PIN(4,  9),	/* AVB0_TD1 */
		[10] = RCAR_GP_PIN(4, 10),	/* AVB0_TD2 */
		[11] = RCAR_GP_PIN(4, 11),	/* AVB0_TD3 */
		[12] = RCAR_GP_PIN(4, 12),	/* AVB0_TXREFCLK */
		[13] = RCAR_GP_PIN(4, 13),	/* AVB0_MDIO */
		[14] = RCAR_GP_PIN(4, 14),	/* AVB0_MDC */
		[15] = RCAR_GP_PIN(4, 15),	/* AVB0_MAGIC */
		[16] = RCAR_GP_PIN(4, 16),	/* AVB0_PHY_INT */
		[17] = RCAR_GP_PIN(4, 17),	/* AVB0_LINK */
		[18] = RCAR_GP_PIN(4, 18),	/* AVB0_AVTP_MATCH */
		[19] = RCAR_GP_PIN(4, 19),	/* AVB0_AVTP_CAPTURE */
		[20] = RCAR_GP_PIN(4, 20),	/* AVB0_AVTP_PPS */
		[21] = RCAR_GP_PIN(4, 21),	/* PCIE0_CLKREQ_N */
		[22] = RCAR_GP_PIN(4, 22),	/* PCIE1_CLKREQ_N */
		[23] = RCAR_GP_PIN(4, 23),	/* PCIE2_CLKREQ_N */
		[24] = RCAR_GP_PIN(4, 24),	/* PCIE3_CLKREQ_N */
		[25] = RCAR_GP_PIN(4, 25),	/* AVS0 */
		[26] = RCAR_GP_PIN(4, 26),	/* AVS1 */
		[27] = PIN_NONE,
		[28] = PIN_NONE,
		[29] = PIN_NONE,
		[30] = PIN_NONE,
		[31] = PIN_NONE,
	} },
	{ PFC_BIAS_REG(0xc0, 0xe0) {         /* PUEN5, PUD5 */
		[ 0] = RCAR_GP_PIN(5,  0),	/* AVB1_RX_CTL */
		[ 1] = RCAR_GP_PIN(5,  1),	/* AVB1_RXC */
		[ 2] = RCAR_GP_PIN(5,  2),	/* AVB1_RD0 */
		[ 3] = RCAR_GP_PIN(5,  3),	/* AVB1_RD1 */
		[ 4] = RCAR_GP_PIN(5,  4),	/* AVB1_RD2 */
		[ 5] = RCAR_GP_PIN(5,  5),	/* AVB1_RD3 */
		[ 6] = RCAR_GP_PIN(5,  6),	/* AVB1_TX_CTL */
		[ 7] = RCAR_GP_PIN(5,  7),	/* AVB1_TXC */
		[ 8] = RCAR_GP_PIN(5,  8),	/* AVB1_TD0 */
		[ 9] = RCAR_GP_PIN(5,  9),	/* AVB1_TD1 */
		[10] = RCAR_GP_PIN(5, 10),	/* AVB1_TD2 */
		[11] = RCAR_GP_PIN(5, 11),	/* AVB1_TD3 */
		[12] = RCAR_GP_PIN(5, 12),	/* AVB1_TXCREFCLK */
		[13] = RCAR_GP_PIN(5, 13),	/* AVB1_MDIO */
		[14] = RCAR_GP_PIN(5, 14),	/* AVB1_MDC */
		[15] = RCAR_GP_PIN(5, 15),	/* AVB1_MAGIC */
		[16] = RCAR_GP_PIN(5, 16),	/* AVB1_PHY_INT */
		[17] = RCAR_GP_PIN(5, 17),	/* AVB1_LINK */
		[18] = RCAR_GP_PIN(5, 18),	/* AVB1_AVTP_MATCH */
		[19] = RCAR_GP_PIN(5, 19),	/* AVB1_AVTP_CAPTURE */
		[20] = RCAR_GP_PIN(5, 20),	/* AVB1_AVTP_PPS */
		[21] = PIN_NONE,
		[22] = PIN_NONE,
		[23] = PIN_NONE,
		[24] = PIN_NONE,
		[25] = PIN_NONE,
		[26] = PIN_NONE,
		[27] = PIN_NONE,
		[28] = PIN_NONE,
		[29] = PIN_NONE,
		[30] = PIN_NONE,
		[31] = PIN_NONE,
	} },
	{ PFC_BIAS_REG(0xc0, 0xe0) {         /* PUEN6, PUD6 */
		[ 0] = RCAR_GP_PIN(6,  0),	/* AVB2_RX_CTL */
		[ 1] = RCAR_GP_PIN(6,  1),	/* AVB2_RXC */
		[ 2] = RCAR_GP_PIN(6,  2),	/* AVB2_RD0 */
		[ 3] = RCAR_GP_PIN(6,  3),	/* AVB2_RD1 */
		[ 4] = RCAR_GP_PIN(6,  4),	/* AVB2_RD2 */
		[ 5] = RCAR_GP_PIN(6,  5),	/* AVB2_RD3 */
		[ 6] = RCAR_GP_PIN(6,  6),	/* AVB2_TX_CTL */
		[ 7] = RCAR_GP_PIN(6,  7),	/* AVB2_TXC */
		[ 8] = RCAR_GP_PIN(6,  8),	/* AVB2_TD0 */
		[ 9] = RCAR_GP_PIN(6,  9),	/* AVB2_TD1 */
		[10] = RCAR_GP_PIN(6, 10),	/* AVB2_TD2 */
		[11] = RCAR_GP_PIN(6, 11),	/* AVB2_TD3 */
		[12] = RCAR_GP_PIN(6, 12),	/* AVB2_TXCREFCLK */
		[13] = RCAR_GP_PIN(6, 13),	/* AVB2_MDIO */
		[14] = RCAR_GP_PIN(6, 14),	/* AVB2_MDC */
		[15] = RCAR_GP_PIN(6, 15),	/* AVB2_MAGIC */
		[16] = RCAR_GP_PIN(6, 16),	/* AVB2_PHY_INT */
		[17] = RCAR_GP_PIN(6, 17),	/* AVB2_LINK */
		[18] = RCAR_GP_PIN(6, 18),	/* AVB2_AVTP_MATCH */
		[19] = RCAR_GP_PIN(6, 19),	/* AVB2_AVTP_CAPTURE */
		[20] = RCAR_GP_PIN(6, 20),	/* AVB2_AVTP_PPS */
		[21] = PIN_NONE,
		[22] = PIN_NONE,
		[23] = PIN_NONE,
		[24] = PIN_NONE,
		[25] = PIN_NONE,
		[26] = PIN_NONE,
		[27] = PIN_NONE,
		[28] = PIN_NONE,
		[29] = PIN_NONE,
		[30] = PIN_NONE,
		[31] = PIN_NONE,
	} },
	{ PFC_BIAS_REG(0xc0, 0xe0) {         /* PUEN7, PUD7 */
		[ 0] = RCAR_GP_PIN(7,  0),	/* AVB3_RX_CTL */
		[ 1] = RCAR_GP_PIN(7,  1),	/* AVB3_RXC */
		[ 2] = RCAR_GP_PIN(7,  2),	/* AVB3_RD0 */
		[ 3] = RCAR_GP_PIN(7,  3),	/* AVB3_RD1 */
		[ 4] = RCAR_GP_PIN(7,  4),	/* AVB3_RD2 */
		[ 5] = RCAR_GP_PIN(7,  5),	/* AVB3_RD3 */
		[ 6] = RCAR_GP_PIN(7,  6),	/* AVB3_TX_CTL */
		[ 7] = RCAR_GP_PIN(7,  7),	/* AVB3_TXC */
		[ 8] = RCAR_GP_PIN(7,  8),	/* AVB3_TD0 */
		[ 9] = RCAR_GP_PIN(7,  9),	/* AVB3_TD1 */
		[10] = RCAR_GP_PIN(7, 10),	/* AVB3_TD2 */
		[11] = RCAR_GP_PIN(7, 11),	/* AVB3_TD3 */
		[12] = RCAR_GP_PIN(7, 12),	/* AVB3_TXCREFCLK */
		[13] = RCAR_GP_PIN(7, 13),	/* AVB3_MDIO */
		[14] = RCAR_GP_PIN(7, 14),	/* AVB3_MDC */
		[15] = RCAR_GP_PIN(7, 15),	/* AVB3_MAGIC */
		[16] = RCAR_GP_PIN(7, 16),	/* AVB3_PHY_INT */
		[17] = RCAR_GP_PIN(7, 17),	/* AVB3_LINK */
		[18] = RCAR_GP_PIN(7, 18),	/* AVB3_AVTP_MATCH */
		[19] = RCAR_GP_PIN(7, 19),	/* AVB3_AVTP_CAPTURE */
		[20] = RCAR_GP_PIN(7, 20),	/* AVB3_AVTP_PPS */
		[21] = PIN_NONE,
		[22] = PIN_NONE,
		[23] = PIN_NONE,
		[24] = PIN_NONE,
		[25] = PIN_NONE,
		[26] = PIN_NONE,
		[27] = PIN_NONE,
		[28] = PIN_NONE,
		[29] = PIN_NONE,
		[30] = PIN_NONE,
		[31] = PIN_NONE,
	} },
	{ PFC_BIAS_REG(0xc0, 0xe0) {         /* PUEN8, PUD8 */
		[ 0] = RCAR_GP_PIN(8,  0),	/* AVB4_RX_CTL */
		[ 1] = RCAR_GP_PIN(8,  1),	/* AVB4_RXC */
		[ 2] = RCAR_GP_PIN(8,  2),	/* AVB4_RD0 */
		[ 3] = RCAR_GP_PIN(8,  3),	/* AVB4_RD1 */
		[ 4] = RCAR_GP_PIN(8,  4),	/* AVB4_RD2 */
		[ 5] = RCAR_GP_PIN(8,  5),	/* AVB4_RD3 */
		[ 6] = RCAR_GP_PIN(8,  6),	/* AVB4_TX_CTL */
		[ 7] = RCAR_GP_PIN(8,  7),	/* AVB4_TXC */
		[ 8] = RCAR_GP_PIN(8,  8),	/* AVB4_TD0 */
		[ 9] = RCAR_GP_PIN(8,  9),	/* AVB4_TD1 */
		[10] = RCAR_GP_PIN(8, 10),	/* AVB4_TD2 */
		[11] = RCAR_GP_PIN(8, 11),	/* AVB4_TD3 */
		[12] = RCAR_GP_PIN(8, 12),	/* AVB4_TXCREFCLK */
		[13] = RCAR_GP_PIN(8, 13),	/* AVB4_MDIO */
		[14] = RCAR_GP_PIN(8, 14),	/* AVB4_MDC */
		[15] = RCAR_GP_PIN(8, 15),	/* AVB4_MAGIC */
		[16] = RCAR_GP_PIN(8, 16),	/* AVB4_PHY_INT */
		[17] = RCAR_GP_PIN(8, 17),	/* AVB4_LINK */
		[18] = RCAR_GP_PIN(8, 18),	/* AVB4_AVTP_MATCH */
		[19] = RCAR_GP_PIN(8, 19),	/* AVB4_AVTP_CAPTURE */
		[20] = RCAR_GP_PIN(8, 20),	/* AVB4_AVTP_PPS */
		[21] = PIN_NONE,
		[22] = PIN_NONE,
		[23] = PIN_NONE,
		[24] = PIN_NONE,
		[25] = PIN_NONE,
		[26] = PIN_NONE,
		[27] = PIN_NONE,
		[28] = PIN_NONE,
		[29] = PIN_NONE,
		[30] = PIN_NONE,
		[31] = PIN_NONE,
	} },
	{ PFC_BIAS_REG(0xc0, 0xe0) {         /* PUEN9, PUD9 */
		[ 0] = RCAR_GP_PIN(9,  0),	/* AVB5_RX_CTL */
		[ 1] = RCAR_GP_PIN(9,  1),	/* AVB5_RXC */
		[ 2] = RCAR_GP_PIN(9,  2),	/* AVB5_RD0 */
		[ 3] = RCAR_GP_PIN(9,  3),	/* AVB5_RD1 */
		[ 4] = RCAR_GP_PIN(9,  4),	/* AVB5_RD2 */
		[ 5] = RCAR_GP_PIN(9,  5),	/* AVB5_RD3 */
		[ 6] = RCAR_GP_PIN(9,  6),	/* AVB5_TX_CTL */
		[ 7] = RCAR_GP_PIN(9,  7),	/* AVB5_TXC */
		[ 8] = RCAR_GP_PIN(9,  8),	/* AVB5_TD0 */
		[ 9] = RCAR_GP_PIN(9,  9),	/* AVB5_TD1 */
		[10] = RCAR_GP_PIN(9, 10),	/* AVB5_TD2 */
		[11] = RCAR_GP_PIN(9, 11),	/* AVB5_TD3 */
		[12] = RCAR_GP_PIN(9, 12),	/* AVB5_TXCREFCLK */
		[13] = RCAR_GP_PIN(9, 13),	/* AVB5_MDIO */
		[14] = RCAR_GP_PIN(9, 14),	/* AVB5_MDC */
		[15] = RCAR_GP_PIN(9, 15),	/* AVB5_MAGIC */
		[16] = RCAR_GP_PIN(9, 16),	/* AVB5_PHY_INT */
		[17] = RCAR_GP_PIN(9, 17),	/* AVB5_LINK */
		[18] = RCAR_GP_PIN(9, 18),	/* AVB5_AVTP_MATCH */
		[19] = RCAR_GP_PIN(9, 19),	/* AVB5_AVTP_CAPTURE */
		[20] = RCAR_GP_PIN(9, 20),	/* AVB5_AVTP_PPS */
		[21] = PIN_NONE,
		[22] = PIN_NONE,
		[23] = PIN_NONE,
		[24] = PIN_NONE,
		[25] = PIN_NONE,
		[26] = PIN_NONE,
		[27] = PIN_NONE,
		[28] = PIN_NONE,
		[29] = PIN_NONE,
		[30] = PIN_NONE,
		[31] = PIN_NONE,
	} },
	{ /* sentinel */ },
};

const struct pfc_bias_reg *pfc_rcar_get_bias_regs(void)
{
	return pfc_bias_regs;
}

const struct pfc_drive_reg *pfc_rcar_get_drive_regs(void)
{
	return pfc_drive_regs;
}

int pfc_rcar_get_reg_index(uint8_t pin, uint8_t *reg_index)
{
	uint8_t gpio_group = pin / 32;

	if (RCAR_IS_GP_PIN(pin) == false)
		return -EINVAL;

	/* In devicetree 'reg' property is storted by addresses, but
	 * that does not match gpio bank [0 - 2] order in Renesas
	 * documentation, fix that here.
	 * (Base address given for Bus Domain 0)
	 * Group                         Base address
	 * GPIO Group 0 (Port Group 0)	 H’E605 8000
	 * GPIO Group 1 (Port Group 1)	 H’E605 0000
	 * GPIO Group 2 (Port Group 2)	 H’E605 0800
	 * GPIO Group 3 (Port Group 3)	 H’E605 8800
	 * GPIO Group 4 (Port Group 4)	 H’E606 0000
	 * GPIO Group 5 (Port Group 5)	 H’E606 0800
	 * GPIO Group 6 (Port Group 6)	 H’E606 8000
	 * GPIO Group 7 (Port Group 7)	 H’E606 8800
	 * GPIO Group 8 (Port Group 8)	 H’E606 9000
	 * GPIO Group 9 (Port Group 9)	 H’E606 9800
	 */
	switch (gpio_group) {
	case 0:
		*reg_index = 2;
		break;
	case 1:
		*reg_index = 0;
		break;
	case 2:
		*reg_index = 1;
		break;
	case 3 ... 9:
		*reg_index = gpio_group;
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

