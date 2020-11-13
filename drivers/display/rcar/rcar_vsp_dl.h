#pragma once

#include "rcar_vsp.h"

extern void vsp_dlm_setup(struct vsp_device *vsp);

#if 0
struct vsp_dl_body;

extern void vsp_dl_body_write(struct vsp_dl_body *dlb, uint32_t reg, uint32_t data);

extern vsp_dl_list_commit(vsp_dl_list * dl, uint32_t dl_flags);
#endif