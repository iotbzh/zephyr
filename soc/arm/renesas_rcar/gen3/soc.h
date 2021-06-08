/*
 * Copyright (c) 2021 IoT.bzh
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#ifndef _SOC__H_
#define _SOC__H_

/* Define CMSIS configurations */
#define __CR_REV      1U

/* Do not let CMSIS to handle GIC and Timer */
#define __GIC_PRESENT 0
#define __TIM_PRESENT 0

#if defined(CONFIG_SOC_R8A77951)
#include "pfc-r8a77951.h"
#endif

#endif /* _SOC__H_ */
