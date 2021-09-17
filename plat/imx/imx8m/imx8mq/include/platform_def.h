/*
 * Copyright (c) 2018-2019, ARM Limited and Contributors. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <lib/utils_def.h>

#define PLATFORM_LINKER_FORMAT		"elf64-littleaarch64"
#define PLATFORM_LINKER_ARCH		aarch64

#define PLATFORM_STACK_SIZE		0xb00
#define CACHE_WRITEBACK_GRANULE		64

#define PLAT_PRIMARY_CPU		U(0x0)
#define PLATFORM_MAX_CPU_PER_CLUSTER	U(4)
#define PLATFORM_CLUSTER_COUNT		U(1)
#define PLATFORM_CLUSTER0_CORE_COUNT	U(4)
#define PLATFORM_CLUSTER1_CORE_COUNT	U(0)
#define PLATFORM_CORE_COUNT		(PLATFORM_CLUSTER0_CORE_COUNT)

#define IMX_PWR_LVL0			MPIDR_AFFLVL0
#define IMX_PWR_LVL1			MPIDR_AFFLVL1
#define IMX_PWR_LVL2			MPIDR_AFFLVL2

#define PWR_DOMAIN_AT_MAX_LVL		U(1)
#define PLAT_MAX_PWR_LVL		U(2)
#define PLAT_MAX_OFF_STATE		U(4)
#define PLAT_MAX_RET_STATE		U(1)

#define PLAT_WAIT_RET_STATE		PLAT_MAX_RET_STATE
#define PLAT_WAIT_OFF_STATE		U(2)
#define PLAT_STOP_OFF_STATE		U(3)

#define BL31_BASE			U(0x910000)
#define BL31_LIMIT			U(0x920000)

/* non-secure uboot base */
#define PLAT_NS_IMAGE_OFFSET		U(0x40200000)
#define BL32_FDT_OVERLAY_ADDR		(PLAT_NS_IMAGE_OFFSET + 0x3000000)

/* GICv3 base address */
#define PLAT_GICD_BASE			U(0x38800000)
#define PLAT_GICR_BASE			U(0x38880000)

#define PLAT_VIRT_ADDR_SPACE_SIZE	(1ull << 32)
#define PLAT_PHY_ADDR_SPACE_SIZE	(1ull << 32)

#ifdef SPD_trusty
#define MAX_XLAT_TABLES			5
#define MAX_MMAP_REGIONS		15
#else
#define MAX_XLAT_TABLES			4
#define MAX_MMAP_REGIONS		14
#endif

#ifdef SPD_trusty
#define IMX_TRUSTY_STACK_SIZE 0x100
#endif

#define HAB_RVT_BASE			U(0x00000880) /* HAB_RVT for i.MX8MQ */

#define IMX_BOOT_UART_BASE		U(0x30860000)
#define IMX_BOOT_UART_CLK_IN_HZ		25000000 /* Select 25Mhz oscillator */
#define PLAT_CRASH_UART_BASE		IMX_BOOT_UART_BASE
#define PLAT_CRASH_UART_CLK_IN_HZ	25000000
#define IMX_CONSOLE_BAUDRATE		115200

#define IMX_AIPS_BASE			U(0x30200000)
#define IMX_AIPS_SIZE			U(0xC00000)
#define IMX_AIPS1_BASE			U(0x30200000)
#define IMX_AIPS3_ARB_BASE		U(0x30800000)
#define IMX_OCOTP_BASE			U(0x30350000)
#define IMX_ANAMIX_BASE			U(0x30360000)
#define IMX_CCM_BASE			U(0x30380000)
#define IMX_SRC_BASE			U(0x30390000)
#define IMX_GPC_BASE			U(0x303a0000)
#define IMX_RDC_BASE			U(0x303d0000)
#define IMX_CSU_BASE			U(0x303e0000)
#define IMX_WDOG_BASE			U(0x30280000)
#define IMX_SNVS_BASE			U(0x30370000)
#define IMX_NOC_BASE			U(0x32700000)
#define IMX_TZASC_BASE			U(0x32F80000)
#define IMX_CAAM_BASE			U(0x30900000)
#define IMX_IOMUX_GPR_BASE		U(0x30340000)
#define IMX_DDRC_BASE			U(0x3d400000)
#define IMX_DDRPHY_BASE			U(0x3c000000)
#define IMX_DDR_IPS_BASE		U(0x3d000000)
#define IMX_DDR_IPS_SIZE		U(0x1800000)
#define IMX_DRAM_BASE			U(0x40000000)
#define IMX_DRAM_SIZE			U(0xc0000000)
#define IMX_NS_OCRAM_BASE		U(0x900000)
#define IMX_NS_OCRAM_SIZE		U(0x20000)
#define IMX_CAAM_RAM_BASE		U(0x100000)
#define IMX_CAAM_RAM_SIZE		U(0x10000)
#define IMX_ROM_BASE			U(0x00000000)
#define IMX_ROM_SIZE			U(0x20000)

#define AIPSTZ1_BASE			U(0x301f0000)
#define AIPSTZ2_BASE			U(0x305f0000)
#define AIPSTZ3_BASE			U(0x309f0000)
#define AIPSTZ4_BASE			U(0x32df0000)

#define GPV_BASE			U(0x32000000)
#define GPV_SIZE			U(0x800000)
#define IMX_GIC_BASE			PLAT_GICD_BASE
#define IMX_GIC_SIZE			U(0x200000)

#define WDOG_WSR			U(0x2)
#define WDOG_WCR_WDZST			BIT(0)
#define WDOG_WCR_WDBG			BIT(1)
#define WDOG_WCR_WDE			BIT(2)
#define WDOG_WCR_WDT			BIT(3)
#define WDOG_WCR_SRS			BIT(4)
#define WDOG_WCR_WDA			BIT(5)
#define WDOG_WCR_SRE			BIT(6)
#define WDOG_WCR_WDW			BIT(7)

#define SRC_A53RCR0			U(0x4)
#define SRC_A53RCR1			U(0x8)
#define SRC_M4RCR			U(0xc)
#define SRC_OTG1PHY_SCR			U(0x20)
#define SRC_OTG2PHY_SCR			U(0x24)
#define SRC_GPR1_OFFSET			U(0x74)

#define SRC_SCR_M4_ENABLE_MASK		BIT(3)
#define SRC_SCR_M4C_NON_SCLR_RST_MASK  	BIT(0)
#define IMX_M4_STATUS			(IMX_SRC_BASE + SRC_M4RCR)
#define IMX_M4_ENABLED_MASK		SRC_SCR_M4C_NON_SCLR_RST_MASK
#define LPA_STATUS			U(0x94)

#define SNVS_LPCR			U(0x38)
#define SNVS_LPCR_SRTC_ENV		BIT(0)
#define SNVS_LPCR_DP_EN			BIT(5)
#define SNVS_LPCR_TOP			BIT(6)

#define SAVED_DRAM_TIMING_BASE		0x40000000

#define HW_DRAM_PLL_CFG0		(IMX_ANAMIX_BASE + 0x60)
#define HW_DRAM_PLL_CFG1		(IMX_ANAMIX_BASE + 0x64)
#define HW_DRAM_PLL_CFG2		(IMX_ANAMIX_BASE + 0x68)
#define DRAM_PLL_CTRL			HW_DRAM_PLL_CFG0

#define IOMUXC_GPR10			U(0x28)
#define GPR_TZASC_EN			BIT(0)
#define GPR_TZASC_EN_LOCK		BIT(16)

#define OCRAM_S_BASE			U(0x00180000)
#define OCRAM_S_SIZE			U(0x8000)
#define OCRAM_S_LIMIT			(OCRAM_S_BASE + OCRAM_S_SIZE)

#define IMX_SCTR_BASE			0x306c0000
#define CNTFID0_OFF			U(0x20)
#define CNTFID1_OFF			U(0x24)
#define COUNTER_FREQUENCY		8000000 /* 8MHz */

#define DEBUG_CONSOLE			0
#if !DEBUG_CONSOLE
#undef LOG_LEVEL
#define LOG_LEVEL 			0
#endif

#define IMX_WDOG_B_RESET
