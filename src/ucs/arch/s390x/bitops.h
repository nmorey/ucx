/**
* Copyright (C) Mellanox Technologies Ltd. 2001-2015.  ALL RIGHTS RESERVED.
*
* See file LICENSE for terms.
*/

#ifndef UCS_S390X_BITOPS_H_
#define UCS_S390X_BITOPS_H_

#include <stdint.h>


static inline unsigned __ucs_ilog2_u32(uint32_t n)
{
	if (!n)
		return 0;
	return 31 - __builtin_clz(n);
}

static inline unsigned __ucs_ilog2_u64(uint64_t n)
{
	if (!n)
		return 0;
	return 63 - __builtin_clz(n);
}

static UCS_F_ALWAYS_INLINE unsigned ucs_ffs32(uint32_t n)
{
    return __ucs_ilog2_u32(n & -n);
}

static inline unsigned ucs_ffs64(uint64_t n)
{
    return __ucs_ilog2_u64(n & -n);
}

#endif
