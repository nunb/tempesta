/**
 * \file entropy_poll.h
 *
 * \brief Platform-specific and custom entropy polling functions
 */
/*
 *  Copyright (C) 2006-2016, ARM Limited, All Rights Reserved
 *  Copyright (C) 2015-2018 Tempesta Technologies, Inc.
 *  SPDX-License-Identifier: GPL-2.0
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 *  This file is part of mbed TLS (https://tls.mbed.org)
 */
#ifndef MBEDTLS_ENTROPY_POLL_H
#define MBEDTLS_ENTROPY_POLL_H

#if !defined(MBEDTLS_CONFIG_FILE)
#include "config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif

#include <stddef.h>

/*
 * Default thresholds for built-in sources, in bytes
 */
#define MBEDTLS_ENTROPY_MIN_PLATFORM	 32	 /**< Minimum for platform source	*/
#define MBEDTLS_ENTROPY_MIN_HAVEGE	   32	 /**< Minimum for HAVEGE			 */
#define MBEDTLS_ENTROPY_MIN_HARDCLOCK	 4	 /**< Minimum for mbedtls_timing_hardclock()		*/
#define MBEDTLS_ENTROPY_MIN_HARDWARE	 32	 /**< Minimum for the hardware source */

#if defined(MBEDTLS_HAVEGE_C)
/**
 * \brief		   HAVEGE based entropy poll callback
 *
 * Requires an HAVEGE state as its data pointer.
 */
int mbedtls_havege_poll(void *data,
				 unsigned char *output, size_t len, size_t *olen);
#endif

/**
 * \brief		   mbedtls_timing_hardclock-based entropy poll callback
 */
int mbedtls_hardclock_poll(void *data,
					unsigned char *output, size_t len, size_t *olen);

/**
 * \brief		   Entropy poll callback for a hardware source
 * \note			This must accept NULL as its first argument.
 */
int mbedtls_hardware_poll(void *data,
						   unsigned char *output, size_t len, size_t *olen);
#endif /* entropy_poll.h */
