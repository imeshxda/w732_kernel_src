/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
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

#ifndef _CUST_BAT_H_
#define _CUST_BAT_H_

#ifndef PHILIPS_ATLAS
#define PHILIPS_ATLAS
#endif

typedef enum
{
	Cust_CC_1600MA = 0x0,
	Cust_CC_1500MA = 0x1,
	Cust_CC_1400MA = 0x2,
	Cust_CC_1300MA = 0x3,
	Cust_CC_1200MA = 0x4,
	Cust_CC_1100MA = 0x5,
	Cust_CC_1000MA = 0x6,
	Cust_CC_900MA  = 0x7,
	Cust_CC_800MA  = 0x8,
	Cust_CC_700MA  = 0x9,
	Cust_CC_650MA  = 0xA,
	Cust_CC_550MA  = 0xB,
	Cust_CC_450MA  = 0xC,
	Cust_CC_400MA  = 0xD,
	Cust_CC_200MA  = 0xE,
	Cust_CC_70MA   = 0xF,
	Cust_CC_0MA	   = 0xDD
}cust_charging_current_enum;

typedef struct{	
	unsigned int BattVolt;
	unsigned int BattPercent;
}VBAT_TO_PERCENT;

/* Battery Temperature Protection */
#if defined(ACER_C8)
#define MAX_CHARGE_TEMPERATURE  50
#define MIN_CHARGE_TEMPERATURE  0
#elif defined(PHILIPS_ATLAS)||defined(SIMCOM_I5000)||defined(PHILIPS_TITAN)||defined(SIMCOM_I3000)//amy0504 
#define MAX_CHARGE_TEMPERATURE  55
#define MIN_CHARGE_TEMPERATURE  -15
#else
#define MAX_CHARGE_TEMPERATURE  50
#define MIN_CHARGE_TEMPERATURE  0
#endif
#define ERR_CHARGE_TEMPERATURE  0xFF

/* Recharging Battery Voltage */
#define RECHARGING_VOLTAGE      4110

/* Charging Current Setting */
#define CONFIG_USB_IF 						0   
#define USB_CHARGER_CURRENT_SUSPEND			Cust_CC_0MA		// def CONFIG_USB_IF
#define USB_CHARGER_CURRENT_UNCONFIGURED	Cust_CC_70MA	// def CONFIG_USB_IF
#define USB_CHARGER_CURRENT_CONFIGURED		Cust_CC_450MA	// def CONFIG_USB_IF
#define USB_CHARGER_CURRENT					Cust_CC_450MA
#if defined(PHILIPS_ATLAS) || defined(ACER_C8)||defined(SIMCOM_I5000)||defined(PHILIPS_TITAN) //amy0504
#if defined(I5000_P150) || defined(I5000_P14)
#define AC_CHARGER_CURRENT					Cust_CC_550MA
#else	
#define AC_CHARGER_CURRENT					Cust_CC_1000MA	
#endif
#elif defined(SIMCOM_I3000)
#define AC_CHARGER_CURRENT					Cust_CC_550MA
#else
#define AC_CHARGER_CURRENT					Cust_CC_700MA	
#endif

/* Battery Meter Solution */
#define CONFIG_ADC_SOLUTION 	1

/* Battery Voltage and Percentage Mapping Table */
VBAT_TO_PERCENT Batt_VoltToPercent_Table[] = {
	/*BattVolt,BattPercent*/
	{3400,0},
	{3641,10},
	{3708,20},
	{3741,30},
	{3765,40},
	{3793,50},
	{3836,60},
	{3891,70},
	{3960,80},
	{4044,90},
	{4183,100},
};

/* Precise Tunning */
//#define BATTERY_AVERAGE_SIZE 	30
#define BATTERY_AVERAGE_SIZE   12

/* Common setting */
#define R_CURRENT_SENSE 2				// 0.2 Ohm
#define R_BAT_SENSE 4					// times of voltage
#define R_I_SENSE 4						// times of voltage
#define R_CHARGER_1 330
#define R_CHARGER_2 39
#define R_CHARGER_SENSE ((R_CHARGER_1+R_CHARGER_2)/R_CHARGER_2)	// times of voltage
//#define V_CHARGER_MAX 6000				// 6 V
#define V_CHARGER_MAX 6500				// 6.5 V
#if defined(PHILIPS_ATLAS)||defined(PHILIPS_TITAN)
#define V_CHARGER_MIN 4300				// 4.4 V
#else
#define V_CHARGER_MIN 4400				// 4.4 V
#endif
#if defined(ACER_C8)||defined(PHILIPS_ATLAS)||defined(SIMCOM_I5000)||defined(PHILIPS_TITAN) //amy0504
#define V_CHARGER_ENABLE 1				// 1:ON , 0:OFF
#elif defined(SIMCOM_I3000)//LK@I3000
  #if defined(AUX_V900)//aux_v900 close v_charger_enable
  #define V_CHARGER_ENABLE 0				// 1:ON , 0:OFF 
  #else
  #define V_CHARGER_ENABLE 1				// 1:ON , 0:OFF
  #endif
#else
#define V_CHARGER_ENABLE 0				// 1:ON , 0:OFF
#endif
#if defined(PHILIPS_ATLAS)||defined(SIMCOM_I5000)||defined(PHILIPS_TITAN)||defined(ACER_C8)
    #define V_CHARGER_COMPATIBLE_ENABLE   1				// 1:ON , 0:OFF 
#else
    #define V_CHARGER_COMPATIBLE_ENABLE   0				// 1:ON , 0:OFF
#endif
#if defined(PHILIPS_ATLAS)||defined(PHILIPS_TITAN)
#define V_CHARGER_COMPATIBLE_M        4500
#define V_CHARGER_COMPATIBLE_V        4350
#else
#define V_CHARGER_COMPATIBLE_V        4500
#endif
#define AC_CHARGER_COMPATIBLE_CURRENT Cust_CC_450MA
#define AC_CHARGER_COMPATIBLE_CNT     3

/* Teperature related setting */
#define RBAT_PULL_UP_R             24000
//#define RBAT_PULL_UP_VOLT          2500
#define RBAT_PULL_UP_VOLT          1200
#if 1//defined(ACER_C8)||defined(PHILIPS_ATLAS)||defined(SIMCOM_I5000)||defined(PHILIPS_TITAN) //amy0504,LK@modify
#define BAT_TEMP_PROTECT_ENABLE    1
#else
#define BAT_TEMP_PROTECT_ENABLE    0
#endif
#define BAT_NTC_10 1
#define BAT_NTC_47 0



#if (BAT_NTC_10 == 1)
#define TBAT_OVER_CRITICAL_LOW     68237
#elif (BAT_NTC_47 == 1)
#define TBAT_OVER_CRITICAL_LOW     483954
#else
xx
#endif

/* Battery Notify */
#define BATTERY_NOTIFY_CASE_0001
#define BATTERY_NOTIFY_CASE_0002
#define BATTERY_NOTIFY_CASE_0003
#define BATTERY_NOTIFY_CASE_0004
#define BATTERY_NOTIFY_CASE_0005
#if defined(ACER_C8)
#define BATTERY_NOTIFY_CASE_0006
#endif

#endif /* _CUST_BAT_H_ */ 
