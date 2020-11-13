/*
 * Copyright (c) 2020 IoT.bzh
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#ifndef _BOARD__H_
#define _BOARD__H_

/* Define CMSIS configurations */
#define __CR_REV		1U

/* Do not let CMSIS to handle GIC an Timer */
#define __GIC_PRESENT 0
#define __TIM_PRESENT 0

/*
 * Supported R-Car devices.
 */
typedef enum {
	RCAR_LSI_H3,	/**< R-Car H3 and H3-N */
	RCAR_LSI_M3W,	/**< R-Car M3-W and M3-W+ */
	RCAR_LSI_V3M,	/**< R-Car V3M */
	RCAR_LSI_V3H,	/**< R-Car V3H */
	RCAR_LSI_D3,	/**< R-Car D3 */
	RCAR_LSI_M3N,	/**< R-Car M3-N */
	RCAR_LSI_E3,	/**< R-Car E3 */
	RCAR_LSI_UNKNOWN_DEVICE,
} RCAR_DEV_NAME_T;

#endif /* _BOARD__H_ */
