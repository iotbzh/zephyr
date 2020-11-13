#pragma once

#include "rcar_vsp_entity.h"

struct vsp_lif {
    struct vsp_entity entity;
};

extern void vsp_lif_write(struct vsp_lif *lif, uint32_t reg, uint32_t data);

extern struct vsp_lif *vsp_lif_create(struct vsp_device *vsp, unsigned int index);
