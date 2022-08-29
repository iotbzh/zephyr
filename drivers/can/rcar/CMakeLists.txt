#
# Copyright (c) 2022 IoT.bzh
#
# SPDX-License-Identifier: Apache-2.0
#

zephyr_library()
zephyr_library_property(ALLOW_EMPTY TRUE)

zephyr_library_sources_ifdef(CONFIG_CAN_RCAR         can_rcar.c)
zephyr_library_sources_ifdef(CONFIG_CAN_FD_RCAR      canfd_rcar.c)
