#ifndef UCM_BISTRO_BISTRO_S390X_H_
#define UCM_BISTRO_BISTRO_S390X_H_

#include <stdint.h>

#include <ucs/type/status.h>
#include <ucs/sys/compiler_def.h>

#define UCM_BISTRO_PROLOGUE
#define UCM_BISTRO_EPILOGUE

typedef struct ucm_bistro_patch {
} UCS_S_PACKED ucm_bistro_patch_t;
typedef struct {
} UCS_S_PACKED ucm_bistro_lock_t;

static inline ucs_status_t ucm_bistro_patch(void *func_ptr, void *hook, const char *symbol,
					    void **orig_func_p,
					    ucm_bistro_restore_point_t **rp){
	return UCS_ERR_UNSUPPORTED;
}

static inline void ucm_bistro_patch_lock(void * UCS_V_UNUSED dst)
{
}

#endif
