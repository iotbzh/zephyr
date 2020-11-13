#include "rcar_fcp.h"

#define LOG_LEVEL CONFIG_DISPLAY_LOG_LEVEL
#include <logging/log.h>
#include <drivers/clock_control.h>


#define DT_DRV_COMPAT renesas_rcar_fcpv

#define CLOCK_CONTROLLER        DT_INST_CLOCKS_LABEL(0)
#define CLOCK_SUBSYS            DT_INST_CLOCKS_CELL(0, module)

#include <logging/log.h>
LOG_MODULE_REGISTER(rcar_fcp);

struct rcar_fcp_data {
	int dummy; // TODO
};

static int fcp_init(const struct device *dev) {

	const struct device *clk;
	int ret;

	LOG_INF("Initializing rcar fcp driver");

	clk = device_get_binding(CLOCK_CONTROLLER);
	if (!clk) {
		return -ENODEV;
	}

	ret = clock_control_on(clk, (clock_control_subsys_t) CLOCK_SUBSYS);
	if (ret < 0) {
		return ret;
	}

	return 0;
}

static struct rcar_fcp_data rcar_fcp_data;


#define RCAR_FCP_INIT(n) \
	DEVICE_AND_API_INIT(vspd, DT_INST_LABEL(n), &fcp_init,\
		    &rcar_fcp_data, NULL, APPLICATION,\
		    CONFIG_APPLICATION_INIT_PRIORITY, NULL);

DT_INST_FOREACH_STATUS_OKAY(RCAR_FCP_INIT)

#if DT_HAS_COMPAT_STATUS_OKAY(DT_DRV_COMPAT)
#warning OKAY
#else
#warning pas OKAY
#endif
