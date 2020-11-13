#include "rcar_vsp_rwpf.h"

#define RPF_MAX_WIDTH				8190
#define RPF_MAX_HEIGHT				8190

void vsp_rpf_write(struct vsp_rwpf *rpf,
		uint32_t reg,
        uint32_t data)
{
    vsp_write(rpf->entity.vsp, reg + rpf->entity.index * VI6_RPF_OFFSET,
			       data);
}

struct vsp_rwpf *vsp_rpf_create(struct vsp_device *vsp, uint32_t index) {
    struct vsp_rwpf *rpf;
    rpf = k_malloc(sizeof(struct vsp_rwpf));

    if (rpf == NULL)
        return -ENOMEM;

    rpf->entity.vsp = vsp;
    rpf->entity.index = index;

    return rpf;
}