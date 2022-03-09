/*
 * Copyright (c) 2022 IoT.bzh
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_RENESAS_PINCTRL_R8A779F0_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_RENESAS_PINCTRL_R8A779F0_H_

#include "pinctrl-rcar-common.h"

/* Pins declaration */
#define PIN_NONE                   -1
#define PIN_SCIF_CLK               RCAR_GP_PIN(0, 0)
#define PIN_HSCK0                  RCAR_GP_PIN(0, 1)
#define PIN_HRX0                   RCAR_GP_PIN(0, 2)
#define PIN_HTX0                   RCAR_GP_PIN(0, 3)
#define PIN_HCTS0_N                RCAR_GP_PIN(0, 4)
#define PIN_HRTS0_N                RCAR_GP_PIN(0, 5)
#define PIN_RX0                    RCAR_GP_PIN(0, 6)
#define PIN_TX0                    RCAR_GP_PIN(0, 7)
#define PIN_SCK0                   RCAR_GP_PIN(0, 8)
#define PIN_RTS0_N                 RCAR_GP_PIN(0, 9)
#define PIN_CTS0_N                 RCAR_GP_PIN(0, 10)
#define PIN_MSIOF0_SYNC            RCAR_GP_PIN(0, 11)
#define PIN_MSIOF0_RXD             RCAR_GP_PIN(0, 12)
#define PIN_MSIOF0_TXD             RCAR_GP_PIN(0, 13)
#define PIN_MSIOF0_SCK             RCAR_GP_PIN(0, 14)
#define PIN_MSIOF0_SS1             RCAR_GP_PIN(0, 15)
#define PIN_MSIOF0_SS2             RCAR_GP_PIN(0, 16)
#define PIN_IRQ0                   RCAR_GP_PIN(0, 17)
#define PIN_IRQ1                   RCAR_GP_PIN(0, 18)
#define PIN_IRQ2                   RCAR_GP_PIN(0, 19)
#define PIN_IRQ3                   RCAR_GP_PIN(0, 20)
#define PIN_GP1_00                 RCAR_GP_PIN(1, 0)
#define PIN_GP1_01                 RCAR_GP_PIN(1, 1)
#define PIN_GP1_02                 RCAR_GP_PIN(1, 2)
#define PIN_GP1_03                 RCAR_GP_PIN(1, 3)
#define PIN_GP1_04                 RCAR_GP_PIN(1, 4)
#define PIN_GP1_05                 RCAR_GP_PIN(1, 5)
#define PIN_GP1_06                 RCAR_GP_PIN(1, 6)
#define PIN_GP1_07                 RCAR_GP_PIN(1, 7)
#define PIN_GP1_08                 RCAR_GP_PIN(1, 8)
#define PIN_GP1_09                 RCAR_GP_PIN(1, 9)
#define PIN_GP1_10                 RCAR_GP_PIN(1, 10)
#define PIN_GP1_11                 RCAR_GP_PIN(1, 11)
#define PIN_MMC_SD_CLK             RCAR_GP_PIN(1, 12)
#define PIN_MMC_SD_D0              RCAR_GP_PIN(1, 13)
#define PIN_MMC_SD_D1              RCAR_GP_PIN(1, 14)
#define PIN_MMC_SD_D2              RCAR_GP_PIN(1, 15)
#define PIN_MMC_SD_D3              RCAR_GP_PIN(1, 16)
#define PIN_MMC_D5                 RCAR_GP_PIN(1, 17)
#define PIN_MMC_D4                 RCAR_GP_PIN(1, 18)
#define PIN_MMC_D6                 RCAR_GP_PIN(1, 19)
#define PIN_MMC_DS                 RCAR_GP_PIN(1, 20)
#define PIN_MMC_D7                 RCAR_GP_PIN(1, 21)
#define PIN_MMC_SD_CMD             RCAR_GP_PIN(1, 22)
#define PIN_SD_CD                  RCAR_GP_PIN(1, 23)
#define PIN_SD_WP                  RCAR_GP_PIN(1, 24)
#define PIN_RPC_INT_N              RCAR_GP_PIN(2, 0)
#define PIN_RPC_WP_N               RCAR_GP_PIN(2, 1)
#define PIN_RPC_RESET_N            RCAR_GP_PIN(2, 2)
#define PIN_QSPI1_SSL              RCAR_GP_PIN(2, 3)
#define PIN_QSPI1_IO3              RCAR_GP_PIN(2, 4)
#define PIN_QSPI1_MISO_IO1         RCAR_GP_PIN(2, 5)
#define PIN_QSPI1_IO2              RCAR_GP_PIN(2, 6)
#define PIN_QSPI1_MOSI_IO0         RCAR_GP_PIN(2, 7)
#define PIN_QSPI1_SPCLK            RCAR_GP_PIN(2, 8)
#define PIN_QSPI0_MOSI_IO0         RCAR_GP_PIN(2, 9)
#define PIN_QSPI0_SPCLK            RCAR_GP_PIN(2, 10)
#define PIN_QSPI0_IO2              RCAR_GP_PIN(2, 11)
#define PIN_QSPI0_MISO_IO1         RCAR_GP_PIN(2, 12)
#define PIN_QSPI0_SSL              RCAR_GP_PIN(2, 13)
#define PIN_QSPI0_IO3              RCAR_GP_PIN(2, 14)
#define PIN_PCIE0_CLKREQ_N         RCAR_GP_PIN(2, 15)
#define PIN_PCIE1_CLKREQ_N         RCAR_GP_PIN(2, 16)
#define PIN_TSN1_MDIO              RCAR_GP_PIN(3, 0)
#define PIN_TSN2_MDIO              RCAR_GP_PIN(3, 1)
#define PIN_TSN0_MDIO              RCAR_GP_PIN(3, 2)
#define PIN_TSN2_MDC               RCAR_GP_PIN(3, 3)
#define PIN_TSN0_MDC               RCAR_GP_PIN(3, 4)
#define PIN_TSN1_MDC               RCAR_GP_PIN(3, 5)
#define PIN_TSN1_LINK              RCAR_GP_PIN(3, 6)
#define PIN_TSN2_LINK              RCAR_GP_PIN(3, 7)
#define PIN_TSN0_LINK              RCAR_GP_PIN(3, 8)
#define PIN_TSN2_PHY_INT           RCAR_GP_PIN(3, 9)
#define PIN_TSN0_PHY_INT           RCAR_GP_PIN(3, 10)
#define PIN_TSN1_PHY_INT           RCAR_GP_PIN(3, 11)
#define PIN_TSN0_MAGIC             RCAR_GP_PIN(3, 12)
#define PIN_TSN1_AVTP_PPS          RCAR_GP_PIN(3, 13)
#define PIN_TSN1_AVTP_MATCH        RCAR_GP_PIN(3, 14)
#define PIN_TSN1_AVTP_CAPTURE      RCAR_GP_PIN(3, 15)
#define PIN_TSN0_AVTP_PPS          RCAR_GP_PIN(3, 16)
#define PIN_TSN0_AVTP_MATCH        RCAR_GP_PIN(3, 17)
#define PIN_TSN0_AVTP_CAPTURE      RCAR_GP_PIN(3, 18)
#define PIN_GP4_00                 RCAR_GP_PIN(4, 0)
#define PIN_GP4_01                 RCAR_GP_PIN(4, 1)
#define PIN_GP4_02                 RCAR_GP_PIN(4, 2)
#define PIN_GP4_03                 RCAR_GP_PIN(4, 3)
#define PIN_GP4_04                 RCAR_GP_PIN(4, 4)
#define PIN_GP4_05                 RCAR_GP_PIN(4, 5)
#define PIN_GP4_06                 RCAR_GP_PIN(4, 6)
#define PIN_GP4_07                 RCAR_GP_PIN(4, 7)
#define PIN_GP4_08                 RCAR_GP_PIN(4, 8)
#define PIN_GP4_09                 RCAR_GP_PIN(4, 9)
#define PIN_GP4_10                 RCAR_GP_PIN(4, 10)
#define PIN_GP4_11                 RCAR_GP_PIN(4, 11)
#define PIN_GP4_12                 RCAR_GP_PIN(4, 12)
#define PIN_GP4_13                 RCAR_GP_PIN(4, 13)
#define PIN_GP4_14                 RCAR_GP_PIN(4, 14)
#define PIN_GP4_15                 RCAR_GP_PIN(4, 15)
#define PIN_GP4_16                 RCAR_GP_PIN(4, 16)
#define PIN_GP4_17                 RCAR_GP_PIN(4, 17)
#define PIN_GP4_18                 RCAR_GP_PIN(4, 18)
#define PIN_GP4_19                 RCAR_GP_PIN(4, 19)
#define PIN_MSPI0SC                RCAR_GP_PIN(4, 20)
#define PIN_MSPI0SI                RCAR_GP_PIN(4, 21)
#define PIN_MSPI0SO_MSPI0DCS       RCAR_GP_PIN(4, 22)
#define PIN_MSPI0CSS1              RCAR_GP_PIN(4, 23)
#define PIN_MSPI0CSS0              RCAR_GP_PIN(4, 24)
#define PIN_MSPI1SI                RCAR_GP_PIN(4, 25)
#define PIN_MSPI1SO_MSPI1DCS       RCAR_GP_PIN(4, 26)
#define PIN_MSPI1CSS0              RCAR_GP_PIN(4, 27)
#define PIN_MSPI1SC                RCAR_GP_PIN(4, 28)
#define PIN_MSPI1CSS2              RCAR_GP_PIN(4, 29)
#define PIN_MSPI1CSS1              RCAR_GP_PIN(4, 30)
#define PIN_RIIC0SCL               RCAR_GP_PIN(5, 0)
#define PIN_RIIC0SDA               RCAR_GP_PIN(5, 1)
#define PIN_ETNB0MD                RCAR_GP_PIN(5, 2)
#define PIN_ETNB0WOL               RCAR_GP_PIN(5, 3)
#define PIN_ETNB0LINKSTA           RCAR_GP_PIN(5, 4)
#define PIN_ETNB0MDC               RCAR_GP_PIN(5, 5)
#define PIN_ETNB0RXER              RCAR_GP_PIN(5, 6)
#define PIN_ETNB0RXD3              RCAR_GP_PIN(5, 7)
#define PIN_ETNB0RXD1              RCAR_GP_PIN(5, 8)
#define PIN_ETNB0RXD2              RCAR_GP_PIN(5, 9)
#define PIN_ETNB0RXDV              RCAR_GP_PIN(5, 10)
#define PIN_ETNB0RXD0              RCAR_GP_PIN(5, 11)
#define PIN_ETNB0RXCLK             RCAR_GP_PIN(5, 12)
#define PIN_ETNB0TXER              RCAR_GP_PIN(5, 13)
#define PIN_ETNB0TXD3              RCAR_GP_PIN(5, 14)
#define PIN_ETNB0TXCLK             RCAR_GP_PIN(5, 15)
#define PIN_ETNB0TXD1              RCAR_GP_PIN(5, 16)
#define PIN_ETNB0TXD2              RCAR_GP_PIN(5, 17)
#define PIN_ETNB0TXEN              RCAR_GP_PIN(5, 18)
#define PIN_ETNB0TXD0              RCAR_GP_PIN(5, 19)
#define PIN_RLIN37TX               RCAR_GP_PIN(6, 0)
#define PIN_RLIN37RX_INTP23        RCAR_GP_PIN(6, 1)
#define PIN_RLIN36TX               RCAR_GP_PIN(6, 2)
#define PIN_RLIN36RX_INTP22        RCAR_GP_PIN(6, 3)
#define PIN_RLIN35TX               RCAR_GP_PIN(6, 4)
#define PIN_RLIN35RX_INTP21        RCAR_GP_PIN(6, 5)
#define PIN_RLIN34TX               RCAR_GP_PIN(6, 6)
#define PIN_RLIN34RX_INTP20        RCAR_GP_PIN(6, 7)
#define PIN_RLIN33TX               RCAR_GP_PIN(6, 8)
#define PIN_RLIN33RX_INTP19        RCAR_GP_PIN(6, 9)
#define PIN_RLIN32TX               RCAR_GP_PIN(6, 10)
#define PIN_RLIN32RX_INTP18        RCAR_GP_PIN(6, 11)
#define PIN_RLIN31TX               RCAR_GP_PIN(6, 12)
#define PIN_RLIN31RX_INTP17        RCAR_GP_PIN(6, 13)
#define PIN_RLIN30TX               RCAR_GP_PIN(6, 14)
#define PIN_RLIN30RX_INTP16        RCAR_GP_PIN(6, 15)
#define PIN_INTP37                 RCAR_GP_PIN(6, 16)
#define PIN_INTP36                 RCAR_GP_PIN(6, 17)
#define PIN_INTP35                 RCAR_GP_PIN(6, 18)
#define PIN_INTP34                 RCAR_GP_PIN(6, 19)
#define PIN_INTP33                 RCAR_GP_PIN(6, 20)
#define PIN_INTP32                 RCAR_GP_PIN(6, 21)
#define PIN_NMI1                   RCAR_GP_PIN(6, 22)
#define PIN_PRESETOUT1_N           RCAR_GP_PIN(6, 31)
#define PIN_CAN0TX                 RCAR_GP_PIN(7, 0)
#define PIN_CAN0RX_INTP0           RCAR_GP_PIN(7, 1)
#define PIN_CAN1TX                 RCAR_GP_PIN(7, 2)
#define PIN_CAN1RX_INTP1           RCAR_GP_PIN(7, 3)
#define PIN_CAN2TX                 RCAR_GP_PIN(7, 4)
#define PIN_CAN2RX_INTP2           RCAR_GP_PIN(7, 5)
#define PIN_CAN3TX                 RCAR_GP_PIN(7, 6)
#define PIN_CAN3RX_INTP3           RCAR_GP_PIN(7, 7)
#define PIN_CAN4TX                 RCAR_GP_PIN(7, 8)
#define PIN_CAN4RX_INTP4           RCAR_GP_PIN(7, 9)
#define PIN_CAN5TX                 RCAR_GP_PIN(7, 10)
#define PIN_CAN5RX_INTP5           RCAR_GP_PIN(7, 11)
#define PIN_CAN6TX                 RCAR_GP_PIN(7, 12)
#define PIN_CAN6RX_INTP6           RCAR_GP_PIN(7, 13)
#define PIN_CAN7TX                 RCAR_GP_PIN(7, 14)
#define PIN_CAN7RX_INTP7           RCAR_GP_PIN(7, 15)
#define PIN_CAN8TX                 RCAR_GP_PIN(7, 16)
#define PIN_CAN8RX_INTP8           RCAR_GP_PIN(7, 17)
#define PIN_CAN9TX                 RCAR_GP_PIN(7, 18)
#define PIN_CAN9RX_INTP9           RCAR_GP_PIN(7, 19)
#define PIN_CAN10TX                RCAR_GP_PIN(7, 20)
#define PIN_CAN10RX_INTP10         RCAR_GP_PIN(7, 21)
#define PIN_CAN11TX                RCAR_GP_PIN(7, 22)
#define PIN_CAN11RX_INTP11         RCAR_GP_PIN(7, 23)
#define PIN_CAN12TX                RCAR_GP_PIN(7, 24)
#define PIN_CAN12RX_INTP12         RCAR_GP_PIN(7, 25)
#define PIN_CAN13TX                RCAR_GP_PIN(7, 26)
#define PIN_CAN13RX_INTP13         RCAR_GP_PIN(7, 27)
#define PIN_CAN14TX                RCAR_GP_PIN(7, 28)
#define PIN_CAN14RX_INTP14         RCAR_GP_PIN(7, 29)
#define PIN_CAN15TX                RCAR_GP_PIN(7, 30)
#define PIN_CAN15RX_INTP15         RCAR_GP_PIN(7, 31)

/* Pinmux function declarations */
#define FUNC_SCIF_CLK              IP0SR0(0, 0)
#define FUNC_HSCK0                 IP0SR0(4, 0)
#define FUNC_SCK3                  IP0SR0(4, 1)
#define FUNC_MSIOF3_SCK            IP0SR0(4, 2)
#define FUNC_TSN0_AVTP_CAPTURE_A   IP0SR0(4, 5)
#define FUNC_HRX0                  IP0SR0(8, 0)
#define FUNC_RX3                   IP0SR0(8, 1)
#define FUNC_MSIOF3_RXD            IP0SR0(8, 2)
#define FUNC_TSN0_AVTP_MATCH_A     IP0SR0(8, 5)
#define FUNC_HTX0                  IP0SR0(12, 0)
#define FUNC_TX3                   IP0SR0(12, 1)
#define FUNC_MSIOF3_TXD            IP0SR0(12, 2)
#define FUNC_HCTS0_N               IP0SR0(16, 0)
#define FUNC_CTS3_N                IP0SR0(16, 1)
#define FUNC_MSIOF3_SS1            IP0SR0(16, 2)
#define FUNC_TSN0_MDC_A            IP0SR0(16, 5)
#define FUNC_HRTS0_N               IP0SR0(20, 0)
#define FUNC_RTS3_N                IP0SR0(20, 1)
#define FUNC_MSIOF3_SS2            IP0SR0(20, 2)
#define FUNC_TSN0_MDIO_A           IP0SR0(20, 5)
#define FUNC_RX0                   IP0SR0(24, 0)
#define FUNC_HRX1                  IP0SR0(24, 1)
#define FUNC_MSIOF1_RXD            IP0SR0(24, 3)
#define FUNC_TSN1_AVTP_MATCH_A     IP0SR0(24, 5)
#define FUNC_TX0                   IP0SR0(28, 0)
#define FUNC_HTX1                  IP0SR0(28, 1)
#define FUNC_MSIOF1_TXD            IP0SR0(28, 3)
#define FUNC_TSN1_AVTP_CAPTURE_A   IP0SR0(28, 5)
#define FUNC_SCK0                  IP1SR0(0, 0)
#define FUNC_HSCK1                 IP1SR0(0, 1)
#define FUNC_MSIOF1_SCK            IP1SR0(0, 3)
#define FUNC_RTS0_N                IP1SR0(4, 0)
#define FUNC_HRTS1_N               IP1SR0(4, 1)
#define FUNC_MSIOF3_SYNC           IP1SR0(4, 2)
#define FUNC_TSN1_MDIO_A           IP1SR0(4, 5)
#define FUNC_CTS0_N                IP1SR0(8, 0)
#define FUNC_HCTS1_N               IP1SR0(8, 1)
#define FUNC_MSIOF1_SYNC           IP1SR0(8, 3)
#define FUNC_TSN1_MDC_A            IP1SR0(8, 5)
#define FUNC_MSIOF0_SYNC           IP1SR0(12, 0)
#define FUNC_HCTS3_N               IP1SR0(12, 1)
#define FUNC_CTS1_N                IP1SR0(12, 2)
#define FUNC_IRQ4                  IP1SR0(12, 3)
#define FUNC_TSN0_LINK_A           IP1SR0(12, 5)
#define FUNC_MSIOF0_RXD            IP1SR0(16, 0)
#define FUNC_HRX3                  IP1SR0(16, 1)
#define FUNC_RX1                   IP1SR0(16, 2)
#define FUNC_MSIOF0_TXD            IP1SR0(20, 0)
#define FUNC_HTX3                  IP1SR0(20, 1)
#define FUNC_TX1                   IP1SR0(20, 2)
#define FUNC_MSIOF0_SCK            IP1SR0(24, 0)
#define FUNC_HSCK3                 IP1SR0(24, 1)
#define FUNC_SCK1                  IP1SR0(24, 2)
#define FUNC_MSIOF0_SS1            IP1SR0(28, 0)
#define FUNC_HRTS3_N               IP1SR0(28, 1)
#define FUNC_RTS1_N                IP1SR0(28, 2)
#define FUNC_IRQ5                  IP1SR0(28, 3)
#define FUNC_TSN1_LINK_A           IP1SR0(28, 5)
#define FUNC_MSIOF0_SS2            IP2SR0(0, 0)
#define FUNC_TSN2_LINK_A           IP2SR0(0, 5)
#define FUNC_IRQ0                  IP2SR0(4, 0)
#define FUNC_MSIOF1_SS1            IP2SR0(4, 3)
#define FUNC_TSN0_MAGIC_A          IP2SR0(4, 5)
#define FUNC_IRQ1                  IP2SR0(8, 0)
#define FUNC_MSIOF1_SS2            IP2SR0(8, 3)
#define FUNC_TSN0_PHY_INT_A        IP2SR0(8, 5)
#define FUNC_IRQ2                  IP2SR0(12, 0)
#define FUNC_TSN1_PHY_INT_A        IP2SR0(12, 5)
#define FUNC_IRQ3                  IP2SR0(16, 0)
#define FUNC_TSN2_PHY_INT_A        IP2SR0(16, 5)
#define FUNC_GP1_00                IP0SR1(0, 0)
#define FUNC_TCLK1                 IP0SR1(0, 1)
#define FUNC_HSCK2                 IP0SR1(0, 2)
#define FUNC_GP1_01                IP0SR1(4, 0)
#define FUNC_TCLK4                 IP0SR1(4, 1)
#define FUNC_HRX2                  IP0SR1(4, 2)
#define FUNC_GP1_02                IP0SR1(8, 0)
#define FUNC_HTX2                  IP0SR1(8, 2)
#define FUNC_MSIOF2_SS1            IP0SR1(8, 3)
#define FUNC_TSN2_MDC_A            IP0SR1(8, 5)
#define FUNC_GP1_03                IP0SR1(12, 0)
#define FUNC_TCLK2                 IP0SR1(12, 1)
#define FUNC_HCTS2_N               IP0SR1(12, 2)
#define FUNC_MSIOF2_SS2            IP0SR1(12, 3)
#define FUNC_CTS4_N                IP0SR1(12, 4)
#define FUNC_TSN2_MDIO_A           IP0SR1(12, 5)
#define FUNC_GP1_04                IP0SR1(16, 0)
#define FUNC_TCLK3                 IP0SR1(16, 1)
#define FUNC_HRTS2_N               IP0SR1(16, 2)
#define FUNC_MSIOF2_SYNC           IP0SR1(16, 3)
#define FUNC_RTS4_N                IP0SR1(16, 4)
#define FUNC_GP1_05                IP0SR1(20, 0)
#define FUNC_MSIOF2_SCK            IP0SR1(20, 1)
#define FUNC_SCK4                  IP0SR1(20, 2)
#define FUNC_GP1_06                IP0SR1(24, 0)
#define FUNC_MSIOF2_RXD            IP0SR1(24, 1)
#define FUNC_RX4                   IP0SR1(24, 2)
#define FUNC_GP1_07                IP0SR1(28, 0)
#define FUNC_MSIOF2_TXD            IP0SR1(28, 1)
#define FUNC_TX4                   IP0SR1(28, 2)
#define FUNC_GP4_00                IP0SR4(0, 0)
#define FUNC_MSPI4SC               IP0SR4(0, 1)
#define FUNC_TAUD0I2               IP0SR4(0, 3)
#define FUNC_TAUD0O2               IP0SR4(0, 4)
#define FUNC_GP4_01                IP0SR4(4, 0)
#define FUNC_MSPI4SI               IP0SR4(4, 1)
#define FUNC_TAUD0I4               IP0SR4(4, 3)
#define FUNC_TAUD0O4               IP0SR4(4, 4)
#define FUNC_GP4_02                IP0SR4(8, 0)
#define FUNC_MSPI4SO_MSPI4DCS      IP0SR4(8, 1)
#define FUNC_TAUD0I3               IP0SR4(8, 3)
#define FUNC_TAUD0O3               IP0SR4(8, 4)
#define FUNC_GP4_03                IP0SR4(12, 0)
#define FUNC_MSPI4CSS1             IP0SR4(12, 1)
#define FUNC_TAUD0I6               IP0SR4(12, 3)
#define FUNC_TAUD0O6               IP0SR4(12, 4)
#define FUNC_GP4_04                IP0SR4(16, 0)
#define FUNC_MSPI4CSS0             IP0SR4(16, 1)
#define FUNC_MSPI4SSI_N            IP0SR4(16, 2)
#define FUNC_TAUD0I5               IP0SR4(16, 3)
#define FUNC_TAUD0O5               IP0SR4(16, 4)
#define FUNC_GP4_05                IP0SR4(20, 0)
#define FUNC_MSPI4CSS3             IP0SR4(20, 1)
#define FUNC_TAUD0I8               IP0SR4(20, 3)
#define FUNC_TAUD0O8               IP0SR4(20, 4)
#define FUNC_GP4_06                IP0SR4(24, 0)
#define FUNC_MSPI4CSS2             IP0SR4(24, 1)
#define FUNC_TAUD0I7               IP0SR4(24, 3)
#define FUNC_TAUD0O7               IP0SR4(24, 4)
#define FUNC_GP4_07                IP0SR4(28, 0)
#define FUNC_MSPI4CSS5             IP0SR4(28, 1)
#define FUNC_TAUD0I10              IP0SR4(28, 3)
#define FUNC_TAUD0O10              IP0SR4(28, 4)
#define FUNC_GP4_08                IP1SR4(0,0)
#define FUNC_MSPI4CSS4             IP1SR4(0,1)
#define FUNC_TAUD0I9               IP1SR4(0,3)
#define FUNC_TAUD0O9               IP1SR4(0,4)
#define FUNC_GP4_09                IP1SR4(4,0)
#define FUNC_MSPI4CSS7             IP1SR4(4,1)
#define FUNC_TAUD0I12              IP1SR4(4,3)
#define FUNC_TAUD0O12              IP1SR4(4,4)
#define FUNC_GP4_10                IP1SR4(8,0)
#define FUNC_MSPI4CSS6             IP1SR4(8,1)
#define FUNC_TAUD0I11              IP1SR4(8,3)
#define FUNC_TAUD0O11              IP1SR4(8,4)
#define FUNC_GP4_11                IP1SR4(12,0)
#define FUNC_ERRORIN0_N            IP1SR4(12,1)
#define FUNC_TAUD0I14              IP1SR4(12,3)
#define FUNC_TAUD0O14              IP1SR4(12,4)
#define FUNC_GP4_12                IP1SR4(16,0)
#define FUNC_ERROROUT_C_N          IP1SR4(16,1)
#define FUNC_TAUD0I13              IP1SR4(16,3)
#define FUNC_TAUD0O13              IP1SR4(16,4)
#define FUNC_GP4_13                IP1SR4(20,0)
#define FUNC_GP4_14                IP1SR4(24,0)
#define FUNC_ERRORIN1_N            IP1SR4(24,1)
#define FUNC_TAUD0I15              IP1SR4(24,3)
#define FUNC_TAUD0O15              IP1SR4(24,4)
#define FUNC_GP4_15                IP1SR4(28,0)
#define FUNC_MSPI1CSS3             IP1SR4(28,1)
#define FUNC_TAUD1I1               IP1SR4(28,3)
#define FUNC_TAUD1O1               IP1SR4(28,4)
#define FUNC_GP4_16                IP2SR4(0,0)
#define FUNC_TAUD1I0               IP2SR4(0,3)
#define FUNC_TAUD1O0               IP2SR4(0,4)
#define FUNC_GP4_17                IP2SR4(4,0)
#define FUNC_MSPI1CSS5             IP2SR4(4,1)
#define FUNC_TAUD1I3               IP2SR4(4,3)
#define FUNC_TAUD1O3               IP2SR4(4,4)
#define FUNC_GP4_18                IP2SR4(8,0)
#define FUNC_MSPI1CSS4             IP2SR4(8,1)
#define FUNC_TAUD1I2               IP2SR4(8,3)
#define FUNC_TAUD1O2               IP2SR4(8,4)
#define FUNC_GP4_19                IP2SR4(12,0)
#define FUNC_MSPI1CSS6             IP2SR4(12,1)
#define FUNC_TAUD1I4               IP2SR4(12,3)
#define FUNC_TAUD1O4               IP2SR4(12,4)
#define FUNC_MSPI0SC               IP2SR4(16,0)
#define FUNC_MSPI1CSS7             IP2SR4(16,1)
#define FUNC_TAUD1I5               IP2SR4(16,3)
#define FUNC_TAUD1O5               IP2SR4(16,4)
#define FUNC_MSPI0SI               IP2SR4(20,0)
#define FUNC_TAUD1I7               IP2SR4(20,3)
#define FUNC_TAUD1O7               IP2SR4(20,4)
#define FUNC_MSPI0SO_MSPI0DCS      IP2SR4(24,0)
#define FUNC_TAUD1I6               IP2SR4(24,3)
#define FUNC_TAUD1O6               IP2SR4(24,4)
#define FUNC_MSPI0CSS1             IP2SR4(28,0)
#define FUNC_TAUD1I9               IP2SR4(28,3)
#define FUNC_TAUD1O9               IP2SR4(28,4)
#define FUNC_MSPI0CSS0             IP3SR4(0,0)
#define FUNC_MSPI0SSI_N            IP3SR4(0,1)
#define FUNC_TAUD1I8               IP3SR4(0,3)
#define FUNC_TAUD1O8               IP3SR4(0,4)
#define FUNC_MSPI1SO_MSPI1DCS      IP3SR4(8,0)
#define FUNC_MSPI0CSS3             IP3SR4(8,2)
#define FUNC_TAUD1I11              IP3SR4(8,3)
#define FUNC_TAUD1O11              IP3SR4(8,4)
#define FUNC_MSPI1SC               IP3SR4(16,0)
#define FUNC_MSPI0CSS2             IP3SR4(16,2)
#define FUNC_TAUD1I10              IP3SR4(16,3)
#define FUNC_TAUD1O10              IP3SR4(16,4)
#define FUNC_RIIC0SCL              IP0SR5(0, 0)
#define FUNC_TAUD0I0               IP0SR5(0, 3)
#define FUNC_TAUD0O0               IP0SR5(0, 4)
#define FUNC_RIIC0SDA              IP0SR5(4, 0)
#define FUNC_TAUD0I1               IP0SR5(4, 3)
#define FUNC_TAUD0O1               IP0SR5(4, 4)
#define FUNC_ETNB0MD               IP0SR5(8, 0)
#define FUNC_ETNB0WOL              IP0SR5(12, 0)
#define FUNC_ETNB0LINKSTA          IP0SR5(16, 0)
#define FUNC_ETNB0MDC              IP0SR5(20, 0)
#define FUNC_ETNB0RXCLK            IP0SR5(24, 0)
#define FUNC_ETNB0CRS_DV           IP0SR5(24, 1)
#define FUNC_ETNB0TXCLK            IP0SR5(28, 0)
#define FUNC_ETNB0REFCLK           IP0SR5(28, 1)
#define FUNC_RLIN33TX              IP1SR6(0, 0)
#define FUNC_TAUJ3O3               IP1SR6(0, 3)
#define FUNC_TAUJ3I3               IP1SR6(0, 4)
#define FUNC_NMI1                  IP1SR6(0, 5)
#define FUNC_RLIN33RX_INTP19       IP1SR6(4, 0)
#define FUNC_TAUJ3O2               IP1SR6(4, 3)
#define FUNC_TAUJ3I2               IP1SR6(4, 4)
#define FUNC_RLIN32TX              IP1SR6(8, 0)
#define FUNC_TAUJ3O1               IP1SR6(8, 3)
#define FUNC_TAUJ3I1               IP1SR6(8, 4)
#define FUNC_RLIN32RX_INTP18       IP1SR6(12, 0)
#define FUNC_TAUJ3O0               IP1SR6(12, 3)
#define FUNC_TAUJ3I0               IP1SR6(12, 4)
#define FUNC_INTP35                IP1SR6(12, 5)
#define FUNC_RLIN31TX              IP1SR6(16, 0)
#define FUNC_TAUJ1I3               IP1SR6(16, 3)
#define FUNC_TAUJ1O3               IP1SR6(16, 4)
#define FUNC_INTP34                IP1SR6(16, 5)
#define FUNC_RLIN31RX_INTP17       IP1SR6(20, 0)
#define FUNC_TAUJ1I2               IP1SR6(20, 3)
#define FUNC_TAUJ1O2               IP1SR6(20, 4)
#define FUNC_INTP33                IP1SR6(20, 5)
#define FUNC_RLIN30TX              IP1SR6(24, 0)
#define FUNC_TAUJ1I1               IP1SR6(24, 3)
#define FUNC_TAUJ1O1               IP1SR6(24, 4)
#define FUNC_RLIN30RX_INTP16       IP1SR6(28, 0)
#define FUNC_TAUJ1I0               IP1SR6(28, 3)
#define FUNC_TAUJ1O0               IP1SR6(28, 4)
#define FUNC_FLXA0STPWT            IP2SR6(8, 2)
#define FUNC_CAN0TX                IP0SR7(0, 0)
#define FUNC_RSENT0SPCO            IP0SR7(0, 1)
#define FUNC_MSPI2SO_MSPI2DCS      IP0SR7(0, 3)
#define FUNC_CAN0RX_INTP0          IP0SR7(4, 0)
#define FUNC_RSENT0RX              IP0SR7(4, 1)
#define FUNC_RSENT0RX_RSENT0SPCO   IP0SR7(4, 2)
#define FUNC_MSPI2SC               IP0SR7(4, 3)
#define FUNC_CAN1TX                IP0SR7(8, 0)
#define FUNC_RSENT1SPCO            IP0SR7(8, 1)
#define FUNC_MSPI2SSI_N            IP0SR7(8, 3)
#define FUNC_MSPI2CSS0             IP0SR7(8, 4)
#define FUNC_CAN1RX_INTP1          IP0SR7(12, 0)
#define FUNC_RSENT1RX              IP0SR7(12, 1)
#define FUNC_RSENT1RX_RSENT1SPCO   IP0SR7(12, 2)
#define FUNC_MSPI2SI               IP0SR7(12, 3)
#define FUNC_CAN2TX                IP0SR7(16, 0)
#define FUNC_RSENT2SPCO            IP0SR7(16, 1)
#define FUNC_MSPI2CSS2             IP0SR7(16, 4)
#define FUNC_CAN2RX_INTP2          IP0SR7(20, 0)
#define FUNC_RSENT2RX              IP0SR7(20, 1)
#define FUNC_RSENT2RX_RSENT2SPCO   IP0SR7(20, 2)
#define FUNC_MSPI2CSS1             IP0SR7(20, 4)
#define FUNC_CAN3TX                IP0SR7(24, 0)
#define FUNC_RSENT3SPCO            IP0SR7(24, 1)
#define FUNC_MSPI2CSS4             IP0SR7(24, 4)
#define FUNC_CAN3RX_INTP3          IP0SR7(28, 0)
#define FUNC_RSENT3RX              IP0SR7(28, 1)
#define FUNC_RSENT3RX_RSENT3SPCO   IP0SR7(28, 2)
#define FUNC_MSPI2CSS3             IP0SR7(28, 4)
#define FUNC_CAN4TX                IP1SR7(0, 0)
#define FUNC_RSENT4SPCO            IP1SR7(0, 1)
#define FUNC_MSPI2CSS6             IP1SR7(0, 4)
#define FUNC_CAN4RX_INTP4          IP1SR7(4, 0)
#define FUNC_RSENT4RX              IP1SR7(4, 1)
#define FUNC_RSENT4RX_RSENT4SPCO   IP1SR7(4, 2)
#define FUNC_MSPI2CSS5             IP1SR7(4, 4)
#define FUNC_CAN5TX                IP1SR7(8, 0)
#define FUNC_RSENT5SPCO            IP1SR7(8, 1)
#define FUNC_CAN5RX_INTP5          IP1SR7(12, 0)
#define FUNC_RSENT5RX              IP1SR7(12, 1)
#define FUNC_RSENT5RX_RSENT5SPCO   IP1SR7(12, 2)
#define FUNC_MSPI2CSS7             IP1SR7(12, 4)
#define FUNC_CAN6TX                IP1SR7(16, 0)
#define FUNC_RSENT6SPCO            IP1SR7(16, 1)
#define FUNC_MSPI3SO_MSPI3DCS      IP1SR7(16, 3)
#define FUNC_CAN6RX_INTP6          IP1SR7(20, 0)
#define FUNC_RSENT6RX              IP1SR7(20, 1)
#define FUNC_RSENT6RX_RSENT6SPCO   IP1SR7(20, 2)
#define FUNC_MSPI3SC               IP1SR7(20, 3)
#define FUNC_CAN7TX                IP1SR7(24, 0)
#define FUNC_RSENT7SPCO            IP1SR7(24, 1)
#define FUNC_MSPI3SSI_N            IP1SR7(24, 3)
#define FUNC_CAN7RX_INTP7          IP1SR7(28, 0)
#define FUNC_RSENT7RX              IP1SR7(28, 1)
#define FUNC_RSENT7RX_RSENT7SPCO   IP1SR7(28, 2)
#define FUNC_MSPI3SI               IP1SR7(28, 3)
#define FUNC_CAN8TX                IP2SR7(0, 0)
#define FUNC_RLIN38TX              IP2SR7(0, 1)
#define FUNC_MSPI3CSS1             IP2SR7(0, 3)
#define FUNC_CAN8RX_INTP8          IP2SR7(4, 0)
#define FUNC_RLIN38RX_INTP24       IP2SR7(4, 1)
#define FUNC_MSPI3CSS0             IP2SR7(4, 3)
#define FUNC_CAN9TX                IP2SR7(8, 0)
#define FUNC_RLIN39TX              IP2SR7(8, 1)
#define FUNC_MSPI3CSS3             IP2SR7(8, 3)
#define FUNC_CAN9RX_INTP9          IP2SR7(12, 0)
#define FUNC_RLIN39RX_INTP25       IP2SR7(12, 1)
#define FUNC_MSPI3CSS2             IP2SR7(12, 3)
#define FUNC_CAN10TX               IP2SR7(16, 0)
#define FUNC_RLIN310TX             IP2SR7(16, 1)
#define FUNC_MSPI3CSS5             IP2SR7(16, 3)
#define FUNC_CAN10RX_INTP10        IP2SR7(20, 0)
#define FUNC_RLIN310RX_INTP26      IP2SR7(20, 1)
#define FUNC_MSPI3CSS4             IP2SR7(20, 3)
#define FUNC_CAN11TX               IP2SR7(24, 0)
#define FUNC_RLIN311TX             IP2SR7(24, 1)
#define FUNC_MSPI3CSS7             IP2SR7(24, 3)
#define FUNC_CAN11RX_INTP11        IP2SR7(28, 0)
#define FUNC_RLIN311RX_INTP27      IP2SR7(28, 1)
#define FUNC_MSPI3CSS6             IP2SR7(28, 3)
#define FUNC_FLXA0RXDB             IP3SR7(8, 2)
#define FUNC_FLXA0RXDA             IP3SR7(12, 2)
#define FUNC_FLXA0TXDB             IP3SR7(16, 2)
#define FUNC_FLXA0TXDA             IP3SR7(20, 2)
#define FUNC_FLXA0TXENB            IP3SR7(24, 2)
#define FUNC_FLXA0TXENA            IP3SR7(28, 2)

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_RENESAS_PINCTRL_R8A779F0_H_ */
