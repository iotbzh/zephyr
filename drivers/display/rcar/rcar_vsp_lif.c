#include "rcar_vsp_lif.h"

void vsp_lif_write(struct vsp_lif *lif, uint32_t reg, uint32_t data) {
    vsp_write(lif->entity.vsp, reg + lif->entity.vsp->index, data);
}

struct vsp_lif *vsp_lif_create(struct vsp_device *vsp, unsigned int index) {
	struct vsp_lif *lif;
    lif = k_malloc(sizeof(struct vsp_lif));

    if (lif == NULL)
        return -ENOMEM;

    lif->entity.vsp = vsp;
    lif->entity.index = index;
    return lif;
}
