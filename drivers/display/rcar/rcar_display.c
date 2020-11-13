/*
 * Copyright (c) 2020 Thierry Bultel <thierry.bultel@iot.bzh>
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#define DT_DRV_COMPAT renesas_rcar_display


#include <drivers/display.h>
#include <dt-bindings/rcar/rcar-display.h>

#include "rcar_display.h"
#include "rcar_du.h"
#include "rcar_vsp.h"
#include "rcar_lvds.h"
#include "rcar_hdmi.h"
#include "rcar_display.h"

#define LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL
#include <logging/log.h>
LOG_MODULE_REGISTER(rcar_display);

#include <string.h>
#include <stdio.h>

// TODO define Zone coordinates in device tree
#define X_ORIG	300
#define Y_ORIG	300

#define WIDTH	400
#define HEIGHT	400

const rcar_display_timing_t display_params[] = {
	{
		/* 2560x1600@60Hz using 268.5 MHz pixel clock */
		.hSync = 32,
		.hFront = 80,
		.hActive = 2560,
		.hBack = 48,
		.vFront = 3,
		.vActive = 1600,
		.vBack = 37,
		.vSync = 6,
	},
	{
		/* 1920x1080@60Hz using 148.5 MHz pixel clock */
		.hSync = 44,
		.hFront = 148,
		.hActive = 1920,
		.hBack = 88,
		.vFront = 4,
		.vActive = 1080,
		.vBack = 36,
		.vSync = 5,
	},
	{
		/* 1280x720@60Hz using 74.25 MHz pixel clock */
		.hSync = 40,
		.hFront = 110,
		.hActive = 1280,
		.hBack = 220,
		.vFront = 5,
		.vActive = 720,
		.vBack = 20,
		.vSync = 5,
	},
	{
		/* 1280x800 */
		.hSync = 136,
		.hFront = 64,
		.hActive = 1280,
		.hBack = 200,
		.vFront = 1,
		.vActive = 800,
		.vBack = 24,
		.vSync = 3,
	},
	{
		/* 1024x768@60Hz using 65 MHz pixel clock */
		.hSync = 136,
		.hFront = 20,
		.hActive = 1024,
		.hBack = 160,
		.vFront = 3,
		.vActive = 768,
		.vBack = 29,
		.vSync = 6,
	},
	{
		/* 800x600 */
		.hSync = 128,
		.hFront = 40,
		.hActive = 800,
		.hBack = 88,
		.vFront = 1,
		.vActive = 600,
		.vBack = 23,
		.vSync = 4,
	},
	{
		/* 640x480 */
		.hSync = 96,
		.hFront = 16,
		.hActive = 640,
		.hBack = 48,
		.vFront = 10,
		.vActive = 480,
		.vBack = 33,
		.vSync = 2,
	},
};

typedef struct {
	vspd_channel_t vsp;
	int du;
	int hdmi;
	int lvds;
} rcar_display_pipeline_t;

/* Cf 35.1 of UserManual. This is the list of paths (aka 'pipeline' in DRM world) we support
 * For our demo, only RCAR_DISPLAY_LVDS0_SUPERIMPOSED is of interest
 */

static rcar_display_pipeline_t display_paths[] = {
	{
		.vsp = RCAR_VSPD0,
		.du = RCAR_DU0,
		.hdmi = -1,
		.lvds = RCAR_LVDS0,
	},
	{
		.vsp = RCAR_VSPD1,
		.du = RCAR_DU1,
		.hdmi = -1,
		.lvds = RCAR_LVDS1,
	},
	{
		.vsp = RCAR_VSPD1,
		.du = RCAR_DU1,
		.hdmi = RCAR_HDMI0,
		.lvds = -1,
	},
	{
		.vsp = RCAR_VSPD2,
		.du = RCAR_DU2,
		.hdmi = RCAR_HDMI1,
		.lvds = -1,
	},
	// RCAR_DISPLAY_LVDS0_SUPERIMPOSED. VSPD1 superimposes over VSPD0, on DU0
	{
		.vsp = RCAR_VSPD1,
		.du = RCAR_DU0,
		.hdmi = -1,
		.lvds = RCAR_LVDS0,
	},

};


struct rcar_display_data {
    struct device * vsp;
    rcar_display_pipeline_t * display_path;
	void * fb;
	uint32_t width;
	uint32_t height;
};


static void *rcar_display_get_framebuffer(const struct device *dev)
{
    struct rcar_display_data *data = (struct rcar_display_data *)dev->data;
    struct device *vsp_device  = data->vsp;

    struct vsp_driver_api * api = (struct vsp_driver_api *) vsp_device->api;

    rcar_display_pipeline_t *dp = data->display_path;

 	api->get_resolution(vsp_device, &data->width, &data->height);

    return api->get_framebuffer(vsp_device);

}


static int rcar_display_init(const struct device *dev)
{
	struct rcar_display_data *data = (struct rcar_display_data *)dev->data;

	LOG_INF("Initializing rcar display driver");

    const struct device * vsp = device_get_binding("rcar-vsp");

    if (!vsp) {
		LOG_ERR("Failed to get vsp");
		return -ENOENT;
	}

    data->vsp = (struct device *)vsp;
    data->display_path = &display_paths[DT_INST_PROP(0, display_path)];

	return 0;
}


static int rcar_display_write(const struct device *dev, 
	const uint16_t x,
	const uint16_t y,
	const struct display_buffer_descriptor *desc,
	const void *buf)
{

    struct rcar_display_data *data = (struct rcar_display_data *)dev->data;

//	__ASSERT(desc->width <= desc->pitch, "Pitch is smaller than width");

	if (data->fb == 0) {
		data->fb = rcar_display_get_framebuffer(dev);
	}

	uint32_t *srcbuf = buf;

	// Copy line by line. TODO use DMAC or investigate on HW blending.
	for (int jx = 0; jx < desc->height; jx++) {
		uint32_t *dest = data->fb;
		dest += data->width*(jx+Y_ORIG+y) + x+X_ORIG;
		uint32_t startpos = desc->pitch*jx;
		memcpy(dest, &srcbuf[startpos], desc->pitch*sizeof(uint32_t) );
	}

	return 0;
}

static int rcar_display_read(const struct device *dev, const uint16_t x,
			const uint16_t y,
			const struct display_buffer_descriptor *desc,
			void *buf)
{
	LOG_ERR("Reading not implemented");
	return -ENOTSUP;
}



static int rcar_display_blanking_off(const struct device *dev)
{
//	struct rcar_display_data *data = (struct rcar_display_data *)dev->data;

	LOG_INF("Turning display blanking off");
	return 0;
}

static int rcar_display_blanking_on(const struct device *dev)
{
	//struct rcar_display_data *data = (struct rcar_display_data *)dev->data;

	LOG_INF("Turning display blanking on");
	return 0;
}

static int rcar_display_set_brightness(const struct device *dev,
				  const uint8_t brightness)
{
	LOG_WRN("Set brightness not implemented");
	return -ENOTSUP;
}

static int rcar_display_set_contrast(const struct device *dev, const uint8_t contrast)
{
	LOG_ERR("Set contrast not supported");
	return -ENOTSUP;
}

static int rcar_display_set_pixel_format(const struct device *dev,
				    const enum display_pixel_format
				    pixel_format)
{
	LOG_ERR("Pixel format change not implemented");
	return -ENOTSUP;
}

static int rcar_display_set_orientation(const struct device *dev,
				   const enum display_orientation orientation)
{
	if (orientation == DISPLAY_ORIENTATION_NORMAL) {
		return 0;
	}
	LOG_ERR("Changing display orientation not implemented");
	return -ENOTSUP;
}

static void rcar_display_get_capabilities(const struct device *dev,
				     struct display_capabilities *capabilities)
{
	memset(capabilities, 0, sizeof(struct display_capabilities));

	capabilities->x_resolution = WIDTH;
	capabilities->y_resolution = HEIGHT;
	capabilities->supported_pixel_formats = PIXEL_FORMAT_ARGB_8888;
	capabilities->current_pixel_format = PIXEL_FORMAT_ARGB_8888;

	capabilities->current_orientation = DISPLAY_ORIENTATION_NORMAL;
}



static const struct display_driver_api rcar_display_api = {
	.blanking_on = rcar_display_blanking_on,
	.blanking_off = rcar_display_blanking_off,
	.write = rcar_display_write,
	.read = rcar_display_read,
	.get_framebuffer = rcar_display_get_framebuffer,
	.set_brightness = rcar_display_set_brightness,
	.set_contrast = rcar_display_set_contrast,
	.get_capabilities = rcar_display_get_capabilities,
	.set_pixel_format = rcar_display_set_pixel_format,
	.set_orientation = rcar_display_set_orientation,
};

static struct rcar_display_data rcar_display_data;


#define RCAR_DISPLAY_INIT(n) \
	DEVICE_AND_API_INIT(rcar_display, DT_INST_LABEL(n), &rcar_display_init, \
		    &rcar_display_data, NULL, APPLICATION,\
		    CONFIG_APPLICATION_INIT_PRIORITY, &rcar_display_api);

DT_INST_FOREACH_STATUS_OKAY(RCAR_DISPLAY_INIT)

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)
#warning OKAY
#else
#warning RCAR pas OKAY
#endif
