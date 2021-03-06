/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#ifndef __MVBC_H__
#define __MVBC_H__

#define LED_G0          MPC5XXX_GPIO_SIMPLE_PSC2_0
#define LED_G1          MPC5XXX_GPIO_SIMPLE_PSC2_1
#define LED_Y           MPC5XXX_GPIO_SIMPLE_PSC2_2
#define LED_R           MPC5XXX_GPIO_SIMPLE_PSC2_3
#define ARB_X_EN        MPC5XXX_GPIO_WKUP_PSC2_4

#define FPGA_DIN        MPC5XXX_GPIO_SIMPLE_PSC3_0
#define FPGA_CCLK       MPC5XXX_GPIO_SIMPLE_PSC3_1
#define FPGA_CONF_DONE  MPC5XXX_GPIO_SIMPLE_PSC3_2
#define FPGA_CONFIG     MPC5XXX_GPIO_SIMPLE_PSC3_3
#define FPGA_STATUS     MPC5XXX_GPIO_SINT_PSC3_4

#define MAN_RST         MPC5XXX_GPIO_WKUP_PSC6_0
#define WD_TS           MPC5XXX_GPIO_WKUP_PSC6_1
#define WD_WDI          MPC5XXX_GPIO_SIMPLE_PSC6_2
#define COP_PRESENT     MPC5XXX_GPIO_SIMPLE_PSC6_3
#define FACT_RST        MPC5XXX_GPIO_WKUP_6
#define FLASH_RBY       MPC5XXX_GPIO_WKUP_7

#define SIMPLE_DDR      (LED_G0 | LED_G1 | LED_Y | LED_R | \
			 FPGA_DIN | FPGA_CCLK | FPGA_CONFIG | WD_WDI)
#define SIMPLE_DVO      (FPGA_CONFIG)
#define SIMPLE_ODE      (FPGA_CONFIG | LED_G0 | LED_G1 | LED_Y | LED_R)
#define SIMPLE_GPIOEN   (LED_G0 | LED_G1 | LED_Y | LED_R | \
			 FPGA_DIN | FPGA_CCLK | FPGA_CONF_DONE | FPGA_CONFIG |\
			 WD_WDI | COP_PRESENT)

#define SINT_ODE        0
#define SINT_DDR        0
#define SINT_DVO        0
#define SINT_INTEN      0
#define SINT_ITYPE      0
#define SINT_GPIOEN     (FPGA_STATUS)

#define WKUP_ODE        (MAN_RST)
#define WKUP_DIR        (ARB_X_EN|MAN_RST|WD_TS)
#define WKUP_DO         (ARB_X_EN|MAN_RST|WD_TS)
#define WKUP_EN         (ARB_X_EN|MAN_RST|WD_TS|FACT_RST|FLASH_RBY)

#endif
