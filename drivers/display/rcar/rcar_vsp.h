#pragma once

/*
 * Copyright (c) 2020 Thierry Bultel <thierry.bultel@iot.bzh>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <device.h>
#include "rcar_vsp_regs.h"

typedef enum {
	RCAR_VSPD0,	/* It's VSPDL on H3 */
	RCAR_VSPD1,
	RCAR_VSPD2,
} vspd_channel_t;


struct vsp_lif;
struct vsp_rwpf;


typedef void (*vsp_start_api)(const struct device *dev);
typedef void (*vsp_stop_api)(const struct device *dev);
typedef void * (*vsp_get_framebuffer_api)(const struct device *dev);
typedef void (*vsp_get_resolution_api)(const struct device *dev, uint32_t *width, uint32_t *height);
typedef void (*vsp_set_direct_route_api)(const struct device *dev, uint32_t width, uint32_t height, void *addr);

/**
 * @brief Display driver API
 * API which a display driver should expose
 */
struct vsp_driver_api {
	vsp_start_api start;
	vsp_stop_api stop;
    vsp_get_framebuffer_api get_framebuffer;
	vsp_get_resolution_api get_resolution;
	vsp_set_direct_route_api set_direct_route;
};

struct vsp_device_info {
	uint32_t version;
	const char *model;
	uint32_t gen;
	uint32_t features;
	uint32_t lif_count;
	uint32_t rpf_count;
	uint32_t uds_count;
	uint32_t uif_count;
	uint32_t wpf_count;
	uint32_t num_bru_inputs;
};

#define vsp_feature(vsp1, f) ((vsp)->info->features & (f))

struct rcar_fcp_device;

/* Workaround for hung up at the time of underrun in R-Car H3(ES1.x) */
#define VSP_UNDERRUN_WORKAROUND	BIT(0)

#define VSP_MAX_LIF		2
#define VSP_MAX_RPF		5
#define VSP_MAX_UDS		3
#define VSP_MAX_UIF		2
#define VSP_MAX_WPF		4

#define VSP_HAS_LUT		(1 << 1)
#define VSP_HAS_SRU		(1 << 2)
#define VSP_HAS_BRU		(1 << 3)
#define VSP_HAS_CLU		(1 << 4)
#define VSP_HAS_WPF_VFLIP	(1 << 5)
#define VSP_HAS_WPF_HFLIP	(1 << 6)
#define VSP_HAS_HGO		(1 << 7)
#define VSP_HAS_HGT		(1 << 8)
#define VSP_HAS_BRS		(1 << 9)
#define VSP_HAS_EXT_DL		(1 << 10)

/* TODO move this in a display list manager */
struct vsp_dl_header_list {
	uint32_t num_bytes;
	uint32_t addr;
} __packed;

struct vsp_dl_header {
	uint32_t num_lists;
	struct vsp_dl_header_list lists[8];
	uint32_t next_header;
	uint32_t flags;
} __packed;

struct vsp_dl_body {
	uint32_t addr;
	uint32_t data;
} __packed;

struct vsp_device {

	struct device *dev;
	uint32_t mmio;
	const struct vsp_device_info *info;
	uint32_t version;
	uint32_t ths_quirks;

	struct rcar_fcp_device *fcp;
	struct device *bus_master;

	struct vsp_lif *lif[VSP_MAX_LIF];
	struct vsp_rwpf *rpf[VSP_MAX_RPF];
	struct vsp_rwpf *wpf[VSP_MAX_WPF];

	int index;

	// TODO
	struct vsp_dl_header dl_header;
	struct vsp_dl_body dl_body0;

};

extern uint32_t vsp_read(struct vsp_device *vsp, uint32_t reg);
extern void vsp_write(struct vsp_device *vsp, uint32_t reg, uint32_t data);

extern void vsp_underrun_workaround(struct vsp_device *vsp, bool reset);
