/**
* Copyright (C) Mellanox Technologies Ltd. 2001-2013.  ALL RIGHTS RESERVED.
* Copyright (C) ARM Ltd. 2016-2017.  ALL RIGHTS RESERVED.
*
* See file LICENSE for terms.
*/


#ifndef UCS_S390X_CPU_H_
#define UCS_S390X_CPU_H_

#include <ucs/sys/compiler.h>
#include <ucs/arch/generic/cpu.h>
#include <stdint.h>
#include <string.h>
#include <ucs/type/status.h>


#define UCS_ARCH_CACHE_LINE_SIZE 256

BEGIN_C_DECLS

/* Assume the worst - weak memory ordering */
#define ucs_memory_bus_fence()        asm volatile (""::: "memory")
#define ucs_memory_bus_store_fence()  ucs_memory_bus_fence()
#define ucs_memory_bus_load_fence()   ucs_memory_bus_fence()
#define ucs_memory_bus_cacheline_wc_flush()     ucs_memory_bus_fence()
#define ucs_memory_cpu_fence()        ucs_memory_bus_fence()
#define ucs_memory_cpu_store_fence()  ucs_memory_bus_fence()
#define ucs_memory_cpu_load_fence()   ucs_memory_bus_fence()
#define ucs_memory_cpu_wc_fence()     ucs_memory_bus_fence()


static inline uint64_t ucs_arch_read_hres_clock()
{
    unsigned long  clk;
    asm volatile("stck %0" : "=Q" (clk) : : "cc");
    return clk >> 2;
}
#define ucs_arch_get_clocks_per_sec ucs_arch_generic_get_clocks_per_sec


static inline ucs_cpu_model_t ucs_arch_get_cpu_model()
{
    return UCS_CPU_MODEL_S390X;
}

static inline ucs_cpu_vendor_t ucs_arch_get_cpu_vendor()
{
    return UCS_CPU_VENDOR_GENERIC_IBM;
}

static inline int ucs_arch_get_cpu_flag()
{
    return UCS_CPU_FLAG_UNKNOWN;
}

double ucs_arch_get_clocks_per_sec();

#define ucs_arch_wait_mem ucs_arch_generic_wait_mem

static inline void ucs_cpu_init()
{
}

static inline void *ucs_memcpy_relaxed(void *dst, const void *src, size_t len)
{
    return memcpy(dst, src, len);
}

static UCS_F_ALWAYS_INLINE void
ucs_memcpy_nontemporal(void *dst, const void *src, size_t len)
{
    memcpy(dst, src, len);
}

static inline ucs_status_t ucs_arch_get_cache_size(size_t *cache_sizes)
{
    return UCS_ERR_UNSUPPORTED;
}

END_C_DECLS

#endif
