/*
 * Copyright (c) 2021 IoT.bzh
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#ifndef _PFC_RCAR__H_
#define _PFC_RCAR__H_
#include <stdint.h>
#include <stdbool.h>
#include <devicetree.h>
#include <sys/util.h>

struct rcar_pin {
	/* select pin function */
	uint8_t ipsr_bank;      /* bank number 0 - 18 */
	uint8_t ipsr_shift;     /* bit shift 0 - 28 */
	uint8_t ipsr_val;       /* choice from 0x0 to 0xF */
	/* Select gpio or function */
	uint8_t gpsr_bank;      /* bank number 0 - 7 */
	uint8_t gpsr_num;       /* pin index < 32 */
	bool gpsr_val;          /* gpio:false, peripheral:true */
};

void pinmux_rcar_set_pingroup(const struct rcar_pin *pins, size_t num_pins);

/* Get a node id from a pinctrl-0 prop at index 'i' */
#define NODE_ID_FROM_PINCTRL_0(node_id, i) \
	DT_PHANDLE_BY_IDX(node_id, pinctrl_0, i)

/* Get PIN associated with pinctrl-0 pin at index 'i' */
#define RCAR_IPSR(node_id, i) \
	DT_PROP_BY_IDX(NODE_ID_FROM_PINCTRL_0(node_id, i), renesas_rcar_pins, 0)

/* Get PIN associated with pinctrl-0 pin at index 'i' */
#define RCAR_GPSR(node_id, i) \
	DT_PROP_BY_IDX(NODE_ID_FROM_PINCTRL_0(node_id, i), renesas_rcar_pins, 1)

#define RCAR_DT_PIN(node_id, idx)			\
	{                                               \
	  ((RCAR_IPSR(node_id, idx) >> 10) & 0x1F ),	\
	  (((RCAR_IPSR(node_id, idx) >> 4) & 0x7) * 4),	\
	  ((RCAR_IPSR(node_id, idx) & 0xF)),		\
	  ((RCAR_GPSR(node_id, idx) >> 7) & 0x7),	\
	  ((RCAR_GPSR(node_id, idx) >> 1) & 0x1F),	\
	  ((RCAR_GPSR(node_id, idx) & 0x1)),		\
	}


#define RCAR_DT_INST_PIN(inst, idx) \
	RCAR_DT_PIN(DT_DRV_INST(inst), idx)

/* Get the number of pins for pinctrl-0 */
#define RCAR_DT_NUM_PINS(node_id) DT_PROP_LEN(node_id, pinctrl_0)

#define RCAR_DT_INST_NUM_PINS(inst) \
	RCAR_DT_NUM_PINS(DT_DRV_INST(inst))

/* internal macro to structure things for use with UTIL_LISTIFY */
#define RCAR_DT_PIN_ELEM(idx, node_id) RCAR_DT_PIN(node_id, idx),

/* Construct an array intializer for rcar_pin for a device instance */
#define RCAR_DT_PINS(node_id)				\
	{ UTIL_LISTIFY(RCAR_DT_NUM_PINS(node_id),		\
		       RCAR_DT_PIN_ELEM, node_id)		\
	}


#define RCAR_DT_INST_PINS(inst) \
	RCAR_DT_PINS(DT_DRV_INST(inst))

#endif /* _PFC_RCAR__H_ */
