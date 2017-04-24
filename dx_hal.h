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

/* pseudo dx_hal.h for cc63_perf_test_driver (to be able to include code from CC drivers) */

#ifndef __DX_HAL_H__
#define __DX_HAL_H__

#include <linux/io.h>

#if defined(CONFIG_ARM) || defined(CONFIG_ARM64)
/* CC registers are always 32 bit wide (even on 64 bit platforms) */
#define READ_REGISTER(_addr) ioread32((_addr))
#define WRITE_REGISTER(_addr, _data)  iowrite32((_data), (_addr))
#else
#error Unsupported platform
#endif

#define DX_HAL_WriteCcRegister(offset, val) WRITE_REGISTER(cc_base + offset, val)
#define DX_HAL_ReadCcRegister(offset) READ_REGISTER(cc_base + offset)

#endif
