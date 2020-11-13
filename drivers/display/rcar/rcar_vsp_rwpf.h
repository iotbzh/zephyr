#pragma once

#include "rcar_vsp.h"
#include "rcar_vsp_entity.h"

struct vsp_rwpf {
    struct vsp_entity entity;
	unsigned int max_width;
	unsigned int max_height;
};


extern struct vsp_rwpf *vsp_rpf_create(struct vsp_device *vsp, unsigned int index);
extern struct vsp_rwpf *vsp_wpf_create(struct vsp_device *vsp, unsigned int index);

extern int vsp_reset_wpf(struct vsp_device *vsp, unsigned int index);

extern void vsp_rpf_write(struct vsp_rwpf *rpf,
	uint32_t reg,
    uint32_t data);

extern void vsp_wpf_write(struct vsp_rwpf *rpf,
	uint32_t reg,
    uint32_t data);