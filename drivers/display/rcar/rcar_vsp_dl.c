#include "rcar_vsp_dl.h"

#if 0
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

struct vsp_dl_entry {
	uint32_t addr;
	uint32_t data;
} __packed;


struct vsp_dl_list {
	struct list_head list;
	struct vsp1_dl_header *header;
};

struct vsp1_dl_body {
	struct list_head list;

	struct vsp1_dl_entry *entries;
	dma_addr_t dma;
	size_t size;

	unsigned int num_entries;
	unsigned int max_entries;
};

static vsp_list_init(struct vsp_dl_header * list) {
    memset(list, 0, sizeof(struct vsp_dl_header));
    list->num_lists = 0; /* means 1 */
}
#endif

void vsp_dlm_setup(struct vsp_device *vsp) {
    unsigned int i;
	uint32_t ctrl = (256 << VI6_DL_CTRL_AR_WAIT_SHIFT)
		 | VI6_DL_CTRL_DC2 | VI6_DL_CTRL_DC1 | VI6_DL_CTRL_DLE1
		 | VI6_DL_CTRL_DLE0;
	uint32_t ext_dl = (0x02 << VI6_DL_EXT_CTRL_POLINT_SHIFT)
		   | VI6_DL_EXT_CTRL_DLPRI | VI6_DL_EXT_CTRL_EXT;

	if (vsp_feature(vsp, VSP_HAS_EXT_DL)) {
		for (i = 0; i < vsp->info->wpf_count; ++i)
			vsp_write(vsp, VI6_DL_EXT_CTRL(i), ext_dl);
	}

	vsp_write(vsp, VI6_DL_CTRL, ctrl);
	vsp_write(vsp, VI6_DL_SWAP, VI6_DL_SWAP_LWS);
}
