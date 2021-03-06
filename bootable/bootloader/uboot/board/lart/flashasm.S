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

/*
 * flashasm.S: flash magic for LART
 *
 * Copyright (C) 1999 2000 2001 Jan-Derk bakker (J.D.Bakker@its.tudelft.nl)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

.text


.globl	data_to_flash
.globl	data_from_flash
	/* Subroutine that takes data in r0 and formats it so it will be in */
	/* the correct order for the internal flash */
	/* used for LART only */
data_to_flash:
	mov	r1, #0x0

	tst	r0, #0x00000001
	orrne	r1, r1, #0x00001000
	tst	r0, #0x00000002
	orrne	r1, r1, #0x00004000
	tst	r0, #0x00000004
	orrne	r1, r1, #0x00000800
	tst	r0, #0x00000008
	orrne	r1, r1, #0x00000200
	tst	r0, #0x00000010
	orrne	r1, r1, #0x00000001
	tst	r0, #0x00000020
	orrne	r1, r1, #0x00000004
	tst	r0, #0x00000040
	orrne	r1, r1, #0x00000080
	tst	r0, #0x00000080
	orrne	r1, r1, #0x00000020

	tst	r0, #0x00000100
	orrne	r1, r1, #0x00002000
	tst	r0, #0x00000200
	orrne	r1, r1, #0x00008000
	tst	r0, #0x00000400
	orrne	r1, r1, #0x00000400
	tst	r0, #0x00000800
	orrne	r1, r1, #0x00000100
	tst	r0, #0x00001000
	orrne	r1, r1, #0x00000002
	tst	r0, #0x00002000
	orrne	r1, r1, #0x00000008
	tst	r0, #0x00004000
	orrne	r1, r1, #0x00000040
	tst	r0, #0x00008000
	orrne	r1, r1, #0x00000010

	tst	r0, #0x00010000
	orrne	r1, r1, #0x00100000
	tst	r0, #0x00020000
	orrne	r1, r1, #0x00400000
	tst	r0, #0x00040000
	orrne	r1, r1, #0x00080000
	tst	r0, #0x00080000
	orrne	r1, r1, #0x00020000
	tst	r0, #0x00100000
	orrne	r1, r1, #0x01000000
	tst	r0, #0x00200000
	orrne	r1, r1, #0x04000000
	tst	r0, #0x00400000
	orrne	r1, r1, #0x80000000
	tst	r0, #0x00800000
	orrne	r1, r1, #0x20000000

	tst	r0, #0x01000000
	orrne	r1, r1, #0x00200000
	tst	r0, #0x02000000
	orrne	r1, r1, #0x00800000
	tst	r0, #0x04000000
	orrne	r1, r1, #0x00040000
	tst	r0, #0x08000000
	orrne	r1, r1, #0x00010000
	tst	r0, #0x10000000
	orrne	r1, r1, #0x02000000
	tst	r0, #0x20000000
	orrne	r1, r1, #0x08000000
	tst	r0, #0x40000000
	orrne	r1, r1, #0x40000000
	tst	r0, #0x80000000
	orrne	r1, r1, #0x10000000

	mov	r0, r1
	mov	pc, lr

	/* Takes data received from the flash, and unshuffles it. */
data_from_flash:
	mov	r1, #0x00

	tst	r0, #0x00000001
	orrne	r1, r1, #0x00000010
	tst	r0, #0x00000002
	orrne	r1, r1, #0x00001000
	tst	r0, #0x00000004
	orrne	r1, r1, #0x00000020
	tst	r0, #0x00000008
	orrne	r1, r1, #0x00002000
	tst	r0, #0x00000010
	orrne	r1, r1, #0x00008000
	tst	r0, #0x00000020
	orrne	r1, r1, #0x00000080
	tst	r0, #0x00000040
	orrne	r1, r1, #0x00004000
	tst	r0, #0x00000080
	orrne	r1, r1, #0x00000040

	tst	r0, #0x00000100
	orrne	r1, r1, #0x00000800
	tst	r0, #0x00000200
	orrne	r1, r1, #0x00000008
	tst	r0, #0x00000400
	orrne	r1, r1, #0x00000400
	tst	r0, #0x00000800
	orrne	r1, r1, #0x00000004
	tst	r0, #0x00001000
	orrne	r1, r1, #0x00000001
	tst	r0, #0x00002000
	orrne	r1, r1, #0x00000100
	tst	r0, #0x00004000
	orrne	r1, r1, #0x00000002
	tst	r0, #0x00008000
	orrne	r1, r1, #0x00000200

	tst	r0, #0x00010000
	orrne	r1, r1, #0x08000000
	tst	r0, #0x00020000
	orrne	r1, r1, #0x00080000
	tst	r0, #0x00040000
	orrne	r1, r1, #0x04000000
	tst	r0, #0x00080000
	orrne	r1, r1, #0x00040000
	tst	r0, #0x00100000
	orrne	r1, r1, #0x00010000
	tst	r0, #0x00200000
	orrne	r1, r1, #0x01000000
	tst	r0, #0x00400000
	orrne	r1, r1, #0x00020000
	tst	r0, #0x00800000
	orrne	r1, r1, #0x02000000

	tst	r0, #0x01000000
	orrne	r1, r1, #0x00100000
	tst	r0, #0x02000000
	orrne	r1, r1, #0x10000000
	tst	r0, #0x04000000
	orrne	r1, r1, #0x00200000
	tst	r0, #0x08000000
	orrne	r1, r1, #0x20000000
	tst	r0, #0x10000000
	orrne	r1, r1, #0x80000000
	tst	r0, #0x20000000
	orrne	r1, r1, #0x00800000
	tst	r0, #0x40000000
	orrne	r1, r1, #0x40000000
	tst	r0, #0x80000000
	orrne	r1, r1, #0x00400000

	mov	r0, r1
	mov	pc, lr
