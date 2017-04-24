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


#include "dx_config.h"
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/interrupt.h>
#include <crypto/ctr.h>
#include <linux/pm_runtime.h>
#include "dx_driver.h"
#include "dx_sram_mgr.h"

/*
This function should suspend the HW (if possiable), It should be implemented by 
the driver user. 
The reference code clears the internal SRAM to imitate lose of state. 
*/
void dx_pm_ext_hw_suspend(struct device *dev)
{
	struct dx_drvdata *drvdata =
		(struct dx_drvdata *)dev_get_drvdata(dev);
	unsigned int val;
	void __iomem *cc_base = drvdata->cc_base;
	unsigned int  sram_addr = 0;
#if DX_CC_HAS_ROM 
	sram_addr = READ_REGISTER(cc_base + DX_CC_REG_OFFSET(HOST_RGF, HOST_SEP_SRAM_THRESHOLD));
#endif

	WRITE_REGISTER(cc_base + DX_CC_REG_OFFSET(HOST_RGF, SRAM_ADDR), sram_addr);

	for (;sram_addr < DX_CC_SRAM_SIZE ; sram_addr+=4) {
		WRITE_REGISTER(cc_base + DX_CC_REG_OFFSET(HOST_RGF, SRAM_DATA), 0x0);

		do {
			val = READ_REGISTER(cc_base + DX_CC_REG_OFFSET(HOST_RGF, SRAM_DATA_READY));
		} while (!(val &0x1));
	}
    WRITE_REGISTER(cc_base + DX_CC_REG_OFFSET(HOST_RGF, HOST_CC_SW_RST), 1);

	clk_turn_off(drvdata->plat_dev);
}

/*
This function should resume the HW (if possiable).It should be implemented by 
the driver user. 
*/
void dx_pm_ext_hw_resume(struct device *dev)
{
	struct dx_drvdata *drv_resume = (struct dx_drvdata *)dev_get_drvdata(dev);
	clk_turn_on(drv_resume->plat_dev);

	return;
}

