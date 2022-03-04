/*
 * Copyright (c) 2022 IoT.bzh
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_RENESAS_PINCTRL_R8A779F0_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_RENESAS_PINCTRL_R8A779F0_H_

#include "pinctrl-rcar-common.h"

/* TODO */

/* Pins declaration */
#define PIN_NONE                   -1
#define PIN_RX0                    RCAR_GP_PIN(0, 6)
#define PIN_TX0                    RCAR_GP_PIN(0, 7)
#define PIN_HRX0                   RCAR_GP_PIN(0, 2)
#define PIN_HTX0                   RCAR_GP_PIN(0, 3)

/* Pinmux function declarations */
#define FUNC_RX0               IP0SR0(24, 0)
#define FUNC_TX0               IP0SR0(28, 0)
#define FUNC_RX3               IP0SR0(8, 1)
#define FUNC_TX3               IP0SR0(12, 1)

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_PINCTRL_RENESAS_PINCTRL_R8A779F0_H_ */
