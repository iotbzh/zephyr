
#define LOG_LEVEL CONFIG_DISPLAY_LOG_LEVEL
#include <logging/log.h>
#include <drivers/clock_control.h>
#include <soc.h>

#include "rcar_vsp.h"
#include "rcar_vsp_dl.h"
#include "rcar_vsp_rwpf.h"
#include "rcar_vsp_lif.h"

#define DT_DRV_COMPAT renesas_rcar_vsp

#define CLOCK_CONTROLLER        DT_INST_CLOCKS_LABEL(0)
#define CLOCK_SUBSYS            DT_INST_CLOCKS_CELL(0, module)

#include <logging/log.h>
LOG_MODULE_REGISTER(rcar_vsp);

#if !DT_HAS_CHOSEN(zephyr_graphics_fb)
#error "Sample requires definition of graphics framebuffer address & size"
#endif

/* Constants derived from device tree */
#define FB_NODE		DT_CHOSEN(zephyr_graphics_fb)
#define FB_START_ADDR	DT_REG_ADDR(FB_NODE)
#define FB_SIZE		DT_REG_SIZE(FB_NODE)


static const struct vsp_device_info vsp_device_infos[] = {
	{
		.version = VI6_IP_VERSION_MODEL_VSPS_H2,
		.model = "VSP-S",
		.gen = 2,
		.features = VSP_HAS_BRU | VSP_HAS_CLU | VSP_HAS_HGO
			  | VSP_HAS_HGT | VSP_HAS_LUT | VSP_HAS_SRU
			  | VSP_HAS_WPF_VFLIP,
		.rpf_count = 5,
		.uds_count = 3,
		.wpf_count = 4,
		.num_bru_inputs = 4,
	}, {
		.version = VI6_IP_VERSION_MODEL_VSPR_H2,
		.model = "VSP-R",
		.gen = 2,
		.features = VSP_HAS_BRU | VSP_HAS_SRU | VSP_HAS_WPF_VFLIP,
		.rpf_count = 5,
		.uds_count = 3,
		.wpf_count = 4,
		.num_bru_inputs = 4,
	}, {
		.version = VI6_IP_VERSION_MODEL_VSPD_GEN2,
		.model = "VSP-D",
		.gen = 2,
		.features = VSP_HAS_BRU | VSP_HAS_HGO | VSP_HAS_LUT,
		.lif_count = 1,
		.rpf_count = 4,
		.uds_count = 1,
		.wpf_count = 1,
		.num_bru_inputs = 4,
	}, {
		.version = VI6_IP_VERSION_MODEL_VSPS_M2,
		.model = "VSP-S",
		.gen = 2,
		.features = VSP_HAS_BRU | VSP_HAS_CLU | VSP_HAS_HGO
			  | VSP_HAS_HGT | VSP_HAS_LUT | VSP_HAS_SRU
			  | VSP_HAS_WPF_VFLIP,
		.rpf_count = 5,
		.uds_count = 1,
		.wpf_count = 4,
		.num_bru_inputs = 4,
	}, {
		.version = VI6_IP_VERSION_MODEL_VSPS_V2H,
		.model = "VSPV-S",
		.gen = 2,
		.features = VSP_HAS_BRU | VSP_HAS_CLU | VSP_HAS_LUT
			  | VSP_HAS_SRU | VSP_HAS_WPF_VFLIP,
		.rpf_count = 4,
		.uds_count = 1,
		.wpf_count = 4,
		.num_bru_inputs = 4,
	}, {
		.version = VI6_IP_VERSION_MODEL_VSPD_V2H,
		.model = "VSPV-D",
		.gen = 2,
		.features = VSP_HAS_BRU | VSP_HAS_CLU | VSP_HAS_LUT,
		.lif_count = 1,
		.rpf_count = 4,
		.uds_count = 1,
		.wpf_count = 1,
		.num_bru_inputs = 4,
	}, {
		.version = VI6_IP_VERSION_MODEL_VSPI_GEN3,
		.model = "VSP2-I",
		.gen = 3,
		.features = VSP_HAS_CLU | VSP_HAS_HGO | VSP_HAS_HGT
			  | VSP_HAS_LUT | VSP_HAS_SRU | VSP_HAS_WPF_HFLIP
			  | VSP_HAS_WPF_VFLIP,
		.rpf_count = 1,
		.uds_count = 1,
		.wpf_count = 1,
	}, {
		.version = VI6_IP_VERSION_MODEL_VSPBD_GEN3,
		.model = "VSP2-BD",
		.gen = 3,
		.features = VSP_HAS_BRU | VSP_HAS_WPF_VFLIP,
		.rpf_count = 5,
		.wpf_count = 1,
		.num_bru_inputs = 5,
	}, {
		.version = VI6_IP_VERSION_MODEL_VSPBC_GEN3,
		.model = "VSP2-BC",
		.gen = 3,
		.features = VSP_HAS_BRU | VSP_HAS_CLU | VSP_HAS_HGO
			  | VSP_HAS_LUT | VSP_HAS_WPF_VFLIP,
		.rpf_count = 5,
		.wpf_count = 1,
		.num_bru_inputs = 5,
	}, {
		.version = VI6_IP_VERSION_MODEL_VSPBS_GEN3,
		.model = "VSP2-BS",
		.gen = 3,
		.features = VSP_HAS_BRS | VSP_HAS_WPF_VFLIP,
		.rpf_count = 2,
		.wpf_count = 1,
	}, {
		.version = VI6_IP_VERSION_MODEL_VSPD_GEN3,
		.model = "VSP2-D",
		.gen = 3,
		.features = VSP_HAS_BRU | VSP_HAS_WPF_VFLIP | VSP_HAS_EXT_DL,
		.lif_count = 1,
		.rpf_count = 5,
		.uif_count = 1,
		.wpf_count = 2,
		.num_bru_inputs = 5,
	}, {
		.version = VI6_IP_VERSION_MODEL_VSPD_V3,
		.model = "VSP2-D",
		.gen = 3,
		.features = VSP_HAS_BRS | VSP_HAS_BRU,
		.lif_count = 1,
		.rpf_count = 5,
		.uif_count = 1,
		.wpf_count = 1,
		.num_bru_inputs = 5,
	}, {
		.version = VI6_IP_VERSION_MODEL_VSPDL_GEN3,
		.model = "VSP2-DL",
		.gen = 3,
		.features = VSP_HAS_BRS | VSP_HAS_BRU | VSP_HAS_EXT_DL,
		.lif_count = 2,
		.rpf_count = 5,
		.uif_count = 2,
		.wpf_count = 2,
		.num_bru_inputs = 5,
	},
};


uint32_t vsp_read(struct vsp_device *vsp, uint32_t reg)
{
	return sys_read32(vsp->mmio + reg);
}

void vsp_write(struct vsp_device *vsp, uint32_t reg, uint32_t data)
{
	sys_write32(data, vsp->mmio + reg);
}



static int vsp_device_init(struct vsp_device * vsp) {
unsigned int i;
	int ret;

	/* Reset any channel that might be running. */
	for (i = 0; i < vsp->info->wpf_count; ++i) {
		ret = vsp_reset_wpf(vsp, i);
		if (ret < 0)
			return ret;
	}

	vsp_write(vsp, VI6_CLK_DCSWT, (8 << VI6_CLK_DCSWT_CSTPW_SHIFT) |
		   (8 << VI6_CLK_DCSWT_CSTRW_SHIFT));

	for (i = 0; i < vsp->info->rpf_count; ++i)
		vsp_write(vsp, VI6_DPR_RPF_ROUTE(i), VI6_DPR_NODE_UNUSED);

	for (i = 0; i < vsp->info->uds_count; ++i)
		vsp_write(vsp, VI6_DPR_UDS_ROUTE(i), VI6_DPR_NODE_UNUSED);

	for (i = 0; i < vsp->info->uif_count; ++i)
		vsp_write(vsp, VI6_DPR_UIF_ROUTE(i), VI6_DPR_NODE_UNUSED);

	vsp_write(vsp, VI6_DPR_SRU_ROUTE, VI6_DPR_NODE_UNUSED);
	vsp_write(vsp, VI6_DPR_LUT_ROUTE, VI6_DPR_NODE_UNUSED);
	vsp_write(vsp, VI6_DPR_CLU_ROUTE, VI6_DPR_NODE_UNUSED);
	vsp_write(vsp, VI6_DPR_HST_ROUTE, VI6_DPR_NODE_UNUSED);
	vsp_write(vsp, VI6_DPR_HSI_ROUTE, VI6_DPR_NODE_UNUSED);
	vsp_write(vsp, VI6_DPR_BRU_ROUTE, VI6_DPR_NODE_UNUSED);

	if (vsp_feature(vsp, VSP_HAS_BRS))
		vsp_write(vsp, VI6_DPR_ILV_BRS_ROUTE, VI6_DPR_NODE_UNUSED);

	vsp_write(vsp, VI6_DPR_HGO_SMPPT, (7 << VI6_DPR_SMPPT_TGW_SHIFT) |
		   (VI6_DPR_NODE_UNUSED << VI6_DPR_SMPPT_PT_SHIFT));
	vsp_write(vsp, VI6_DPR_HGT_SMPPT, (7 << VI6_DPR_SMPPT_TGW_SHIFT) |
		   (VI6_DPR_NODE_UNUSED << VI6_DPR_SMPPT_PT_SHIFT));

	vsp_dlm_setup(vsp);

	return 0;
}

void vsp_underrun_workaround(struct vsp_device *vsp, bool reset) {
	LOG_ERR("%s: not implemented\n", __func__);
}


static int vsp_init(const struct device *dev) {

	LOG_INF("Initializing rcar vsp driver");

	struct vsp_device *vsp = (struct vsp_device *)dev->data;
	const struct device *clk;
	int ret;
	int i;

	vsp->mmio = DT_INST_REG_ADDR(0);
	LOG_INF("%s: base address 0x%x\n", __func__, vsp->mmio);

	clk = device_get_binding(CLOCK_CONTROLLER);
	if (!clk) {
		return -ENODEV;
	}

	ret = clock_control_on(clk, (clock_control_subsys_t) CLOCK_SUBSYS);
	if (ret < 0) {
		return ret;
	}

	char * fcpname = DT_LABEL(DT_INST_PHANDLE_BY_IDX(0, renesas_fcp, 0));
	const struct device * fcp = device_get_binding(fcpname);

	if (!fcp) {
		LOG_ERR("Failed to get %s", fcpname);
		return -ENOENT;
	}

	vsp->version = vsp_read(vsp, VI6_IP_VERSION);
	LOG_INF("%s: version %d\n", __func__, vsp->version);

	for (i = 0; i < ARRAY_SIZE(vsp_device_infos); ++i) {
		if ((vsp->version & VI6_IP_VERSION_MODEL_MASK) ==
		    vsp_device_infos[i].version) {
			vsp->info = &vsp_device_infos[i];
			break;
		}
	}

	if (!vsp->info) {
		LOG_ERR("unsupported IP version 0x%08x\n",
			vsp->version);
		ret = -ENXIO;
		goto fail;
	}

	/* disable interrupts */
	for (i = 0; i < vsp->info->lif_count; ++i) {
		vsp_write(vsp, VI6_DISP_IRQ_ENB(i), 0);
		vsp_write(vsp, VI6_WPF_IRQ_ENB(i), 0);
	}

	switch (vsp->mmio) {
		case 0xfea20000:
			vsp->index = 0;
			break;
		case 0xfea28000:
			vsp->index = 1;
			break;
		case 0xfea30000:
			vsp->index = 2;
			break;
		case 0xfea38000:
			vsp->index = 3;
			break;
	}

	ret = vsp_device_init(vsp);
	if (ret < 0) {
		LOG_ERR("%s: device init failed\n", __func__);
		goto fail;
	}


	ret = 0;

fail:
    return ret;
}


static void vsp_start(const struct device *dev) {}
static void vsp_stop (const struct device *dev) {}

static void * vsp_get_framebuffer(const struct device *dev) {
	return NULL;
}

static void vsp_get_resolution(const struct device *dev, uint32_t * width, uint32_t * height) {
}

static void vsp_set_direct_route(const struct device *dev, uint32_t width, uint32_t height, void * addr) {
	struct vsp_device *vsp = (struct vsp_device *)dev->data;

	struct vsp_rwpf *rpf, *wpf;
	struct vsp_lif *lif;
	uint32_t stride;

	uint8_t rpf_index = 0;
	uint8_t wpf_index = 0;
	uint8_t lif_index = 0;

	rpf = vsp_rpf_create(vsp, rpf_index);
	wpf = vsp_wpf_create(vsp, wpf_index);
	lif = vsp_lif_create(vsp, lif_index);

	/* RPF */

	vsp_rpf_write(rpf, VI6_RPF_SRC_BSIZE,
					(width << VI6_RPF_SRC_BSIZE_BHSIZE_SHIFT) |
				(height << VI6_RPF_SRC_BSIZE_BVSIZE_SHIFT));

	/* Not cropping, so extended size is the same */
	vsp_rpf_write(rpf, VI6_RPF_SRC_ESIZE,
		       (width << VI6_RPF_SRC_ESIZE_EHSIZE_SHIFT) |
		       (height << VI6_RPF_SRC_ESIZE_EVSIZE_SHIFT));

	/* This is the only supported format for now */
	vsp_rpf_write(rpf, VI6_RPF_INFMT, VI6_FMT_ARGB_8888);

	/* Use Long Lwords for Plane data swapping  */
	vsp_rpf_write(rpf, VI6_RPF_DSWAP, VI6_RPF_DSWAP_P_LLS | VI6_RPF_DSWAP_P_LWS);

	/* No sublayers */
	vsp_rpf_write(rpf, VI6_RPF_LOC, 0x0);

	stride = ROUND_UP(width, 64);

	vsp_rpf_write(rpf, VI6_RPF_SRCM_PSTRIDE, stride << VI6_RPF_SRCM_PSTRIDE_Y_SHIFT);

	vsp_rpf_write(rpf, VI6_RPF_SRCM_ADDR_Y, (uint32_t) addr);


	/* Minimal display list TODO implement a DL manager */

	memset(&vsp->dl_header, 0 , sizeof(struct vsp_dl_header));
	vsp->dl_header.num_lists = 0; // means 1

		/* Fill 1 entry of DL body */
	vsp->dl_header.lists[0].addr = (uintptr_t)&vsp->dl_body0;
	vsp->dl_header.lists[0].num_bytes = 1 * sizeof(struct vsp_dl_body);
	vsp->dl_header.next_header = (uintptr_t)&vsp->dl_header;

#define VSP_DLH_INT_ENABLE		(1 << 1)
#define VSP_DLH_AUTO_START		(1 << 0)

	vsp->dl_header.flags = VSP_DLH_INT_ENABLE | VSP_DLH_AUTO_START;

	vsp->dl_body0.addr = vsp->mmio + VI6_WPF_IRQ_STA(wpf_index);
	vsp->dl_body0.data = 0;

	vsp_write(vsp, VI6_DL_HDR_ADDR(wpf_index), (uintptr_t)&vsp->dl_header);
	vsp_write(vsp, VI6_DL_SWAP, VI6_DL_SWAP_LWS);

	/*
	 * Disable Extended DL usage. This means only DL header is used.
	 */
	vsp_write(vsp, VI6_DL_EXT_CTRL(wpf_index), 0x00000220);
	vsp_write(vsp, VI6_DL_CTRL, 256 << 16 | wpf_index?VI6_DL_CTRL_DLE1:VI6_DL_CTRL_DLE0 );

	/* WPF */

	/* enables rpf of same index as master layer */
	vsp_wpf_write(wpf, VI6_WPF_SRCRPF, VI6_WPF_SRCRPF_RPF_ACT_MST(rpf_index) );

	/*
	 * VIN stored image format is ARGB each 8 bits.
	 * RPF reads ARGB format & WPF follows the same format.
	 * The below settings covers only this case.
	 */
	vsp_wpf_write(wpf, VI6_WPF_OUTFMT, VI6_FMT_ARGB_8888); /* Refer Table 32.18 */

	vsp_wpf_write(wpf, VI6_WPF_DSWAP, VI6_WPF_DSWAP_P_LLS | VI6_WPF_DSWAP_P_LWS); /* Hard code as per h/w manual */

	vsp_wpf_write(wpf, VI6_WPF_ROT_CTRL, 256); /* Hard code as per h/w manual */

	vsp_wpf_write(wpf, VI6_WPF_WRBCK_CTRL(0), 0);	/* No w/b to mem and only display */

	/* LIF */

	uint32_t obth = 0;
	uint32_t hbth = 0;
	uint32_t lbth = 0;

	uint32_t dev_id;

	switch (vsp->version & VI6_IP_VERSION_MODEL_MASK) {
	case VI6_IP_VERSION_MODEL_VSPD_GEN2:
	case VI6_IP_VERSION_MODEL_VSPD_V2H:
		LOG_ERR("Not supported");
		break;

	case VI6_IP_VERSION_MODEL_VSPDL_GEN3:
	case VI6_IP_VERSION_MODEL_VSPD_V3:
		hbth = 0;
		obth = 1500;
		lbth = 0;
		break;

	case VI6_IP_VERSION_MODEL_VSPD_GEN3:
	default:
		hbth = 0;
		obth = 3000;
		lbth = 0;
		break;
	}

	vsp_lif_write(lif, VI6_LIF_CSBTH,
			(hbth << VI6_LIF_CSBTH_HBTH_SHIFT) |
			(lbth << VI6_LIF_CSBTH_LBTH_SHIFT));

	vsp_lif_write(lif, VI6_LIF_CTRL,
			(obth << VI6_LIF_CTRL_OBTH_SHIFT) |
			/*(format->code == 0 ? VI6_LIF_CTRL_CFMT : 0) |*/
			VI6_LIF_CTRL_REQSEL | VI6_LIF_CTRL_LIF_EN);

	/* Route */

	/* RPF -> WPF is the only path supported at the moment */
	vsp_write(vsp, VI6_DPR_RPF_ROUTE(rpf_index), VI6_DPR_NODE_WPF(wpf_index));



}

static const struct vsp_driver_api vsp_api = {
    .start = vsp_start,
    .stop = vsp_stop,
    .get_framebuffer = vsp_get_framebuffer,
	.get_resolution = vsp_get_resolution,
	.set_direct_route = vsp_set_direct_route,
};

static struct vsp_device vsp_device;

#define RCAR_VSP_INIT(n) \
	DEVICE_AND_API_INIT(vsp, DT_INST_LABEL(n), &vsp_init,\
		    &vsp_device, NULL, APPLICATION,\
		    CONFIG_APPLICATION_INIT_PRIORITY, &vsp_api);

DT_INST_FOREACH_STATUS_OKAY(RCAR_VSP_INIT)

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)
#warning OKAY
#else
#warning pas OKAY
#endif
