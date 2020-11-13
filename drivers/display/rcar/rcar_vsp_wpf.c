#include <logging/log.h>
LOG_MODULE_DECLARE(rcar_vsp);

#include "rcar_vsp_rwpf.h"

int vsp_reset_wpf(struct vsp_device *vsp, unsigned int index)
{
	unsigned int timeout;
	uint32_t status;

	status = vsp_read(vsp, VI6_STATUS);
	if (!(status & VI6_STATUS_SYS_ACT(index)))
		return 0;

	if (vsp->ths_quirks & VSP_UNDERRUN_WORKAROUND)
		vsp_underrun_workaround(vsp, true);
	else
		vsp_write(vsp, VI6_SRESET, VI6_SRESET_SRTS(index));

	for (timeout = 10; timeout > 0; --timeout) {
		status = vsp_read(vsp, VI6_STATUS);
		if (!(status & VI6_STATUS_SYS_ACT(index)))
			break;

		k_sleep(K_MSEC(1000));
	}

	if (!timeout) {
		LOG_ERR("failed to reset wpf.%u\n", index);
		return -ETIMEDOUT;
	}

	return 0;
}

void vsp_wpf_write(struct vsp_rwpf *wpf,
		uint32_t reg,
        uint32_t data)
{
    vsp_write(wpf->entity.vsp, reg + wpf->entity.index * VI6_WPF_OFFSET, data);
}

struct vsp_rwpf *vsp_wpf_create(struct vsp_device *vsp, uint32_t index) {
    struct vsp_rwpf *wpf;
    wpf = k_malloc(sizeof(struct vsp_rwpf));

    if (wpf == NULL)
        return -ENOMEM;

    wpf->entity.vsp = vsp;
    wpf->entity.index = index;

    return wpf;
}