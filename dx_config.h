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

/* \file dx_config.h
   Definitions for Discretix Linux Crypto Driver
 */

#ifndef __DX_CONFIG_H__
#define __DX_CONFIG_H__
#include <linux/version.h>


//#define DISABLE_COHERENT_DMA_OPS
//#define FLUSH_CACHE_ALL
//#define COMPLETION_DELAY
//#define DX_DUMP_DESCS
//#define DX_DUMP_BYTES
// #define DX_DEBUG
//#define ENABLE_CYCLE_COUNT
//#define ENABLE_CC_CYCLE_COUNT
//#define DX_IRQ_DELAY 100000

#ifdef ENABLE_CC_CYCLE_COUNT
#define ENABLE_CYCLE_COUNT
#endif

/* Define the CryptoCell DMA cache coherency signals configuration */
#ifdef DISABLE_COHERENT_DMA_OPS
/* Software Controlled Cache Coherency (SCCC) */
#define DX_CACHE_PARAMS (0x000)
/* CC attached to NONE-ACP such as HPP/ACE/AMBA4.
 * The customer is responsible to enable/disable this feature
 * according to his platform type. */
#define DX_HAS_ACP 0
#else
#if LINUX_VERSION_CODE < KERNEL_VERSION(4,3,0)
#define DX_CACHE_PARAMS (0x277)
#else
#define DX_CACHE_PARAMS (0xEEE)
#endif
/* CC attached to ACP */
#define DX_HAS_ACP 1
#endif

#endif /*__DX_CONFIG_H__*/

