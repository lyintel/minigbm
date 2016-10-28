/*
 * Copyright (c) 2014 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "drv_priv.h"
#include "helpers.h"
#include "util.h"

static struct supported_combination combos[5] = {
	{DRM_FORMAT_ARGB8888, DRM_FORMAT_MOD_NONE, DRV_BO_USE_CURSOR | DRV_BO_USE_LINEAR},
	{DRM_FORMAT_ARGB8888, DRM_FORMAT_MOD_NONE, DRV_BO_USE_RENDERING},
	{DRM_FORMAT_RGB888,   DRM_FORMAT_MOD_NONE, DRV_BO_USE_RENDERING},
	{DRM_FORMAT_XRGB8888, DRM_FORMAT_MOD_NONE, DRV_BO_USE_CURSOR | DRV_BO_USE_LINEAR},
	{DRM_FORMAT_XRGB8888, DRM_FORMAT_MOD_NONE, DRV_BO_USE_RENDERING},
};

static int cirrus_init(struct driver *drv)
{
	drv_insert_combinations(drv, combos, ARRAY_SIZE(combos));
	return drv_add_kms_flags(drv);
}

struct backend backend_cirrus =
{
	.name = "cirrus",
	.init = cirrus_init,
	.bo_create = drv_dumb_bo_create,
	.bo_destroy = drv_dumb_bo_destroy,
	.bo_map = drv_dumb_bo_map,
};
