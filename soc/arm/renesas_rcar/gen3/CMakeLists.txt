# Copyright (c) 2021 IoT.bzh
# SPDX-License-Identifier: Apache-2.0

zephyr_sources(
  soc.c
)

zephyr_library_sources_ifdef(CONFIG_PINMUX_RCAR pinmux_rcar.c)
