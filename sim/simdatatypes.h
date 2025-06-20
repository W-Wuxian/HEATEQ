#ifndef _sim_simdatatypes_h_
#define _sim_simdatatypes_h_

#include "def.h"

BEGIN_C_DECLS

struct sim_fdm_parameter_s;
typedef struct sim_fdm_parameter_s {
    def_int_t    *iparm;
    def_fixdbl_t *dparm;
} sim_fdm_parameter_t;

END_C_DECLS

#endif /* _sim_simdatatypes_h_ */