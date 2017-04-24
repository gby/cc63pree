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


#ifndef __SECURE_KEY_DEFS_H__
#define __SECURE_KEY_DEFS_H__


/******************************************************************************
*				DEFINITIONS
******************************************************************************/

#define DX_SECURE_KEY_PACKAGE_BUF_SIZE_IN_BYTES 	112

#define DX_SECURE_KEY_NONCE_SIZE_IN_BYTES		12

#define DX_SECURE_KEY_MULTI2_MIN_ROUNDS			8
#define DX_SECURE_KEY_MULTI2_MAX_ROUNDS			128
#define DX_SECURE_KEY_MAX_CTR_RANGE_VALUE		0x10000

/******************************************************************************
*				TYPE DEFINITIONS
******************************************************************************/
enum secure_key_type {
	DX_SECURE_KEY_AES_KEY128  = 0,
	DX_SECURE_KEY_AES_KEY256  = 1,
	DX_SECURE_KEY_MULTI2 	  = 2,
	DX_SECURE_KEY_BYPASS 	  = 3,
	DX_SECURE_KEY_MAINTENANCE  = 7,
	DX_SECURE_KEY_KSIZE_RESERVE32B = INT32_MAX
};

enum secure_key_cipher_mode {
	DX_SECURE_KEY_CIPHER_CBC = 1,
	DX_SECURE_KEY_CIPHER_CTR = 2,
	DX_SECURE_KEY_CIPHER_OFB = 6,
	DX_SECURE_KEY_CIPHER_CTR_NONCE_CTR_PROT_NSP = 9,
	DX_SECURE_KEY_CIPHER_CTR_NONCE_PROT = 10,
	DX_SECURE_KEY_CIPHER_CBC_CTS = 11,
	DX_SECURE_KEY_CIPHER_RESERVE32B = INT32_MAX
};

enum secure_key_direction {
	DX_SECURE_KEY_DIRECTION_ENCRYPT = 0,
	DX_SECURE_KEY_DIRECTION_DECRYPT = 1,
	DX_SECURE_KEY_DIRECTION_RESERVE32B = INT32_MAX
};


typedef uint8_t skeyPackageBuf_t[DX_SECURE_KEY_PACKAGE_BUF_SIZE_IN_BYTES];

typedef uint8_t skeyNonceBuf_t[DX_SECURE_KEY_NONCE_SIZE_IN_BYTES];


#endif /*__SECURE_KEY_DEFS_H__*/


