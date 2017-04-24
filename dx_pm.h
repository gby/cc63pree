/*
 * Copyright (C) 2012-2017 ARM Limited or its affiliates.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

/* \file dx_power_mgr.h
    */

#ifndef __POWER_MGR_H__
#define __POWER_MGR_H__


#include "dx_config.h"
#include "dx_driver.h"


#define DX_SUSPEND_TIMEOUT 15000


int dx_power_mgr_init(struct dx_drvdata *drvdata);

void dx_power_mgr_fini(struct dx_drvdata *drvdata);

#if defined (CONFIG_PM_RUNTIME) || defined (CONFIG_PM_SLEEP)
int dx_power_mgr_runtime_suspend(struct device *dev);

int dx_power_mgr_runtime_resume(struct device *dev);

int dx_power_mgr_runtime_get(struct device *dev);

int dx_power_mgr_runtime_put_suspend(struct device *dev);
#endif
#endif /*__POWER_MGR_H__*/

