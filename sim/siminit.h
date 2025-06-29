#ifndef _sim_siminit_h_
#define _sim_siminit_h_

#include "simdatatypes.h"

#define CREATE_IPARM( I ) def_int_t I[IPARM_SIZE]
#define CREATE_DPARM( D ) def_fixdbl_t D[DPARM_SIZE]

#define IS_ARY1D_NULL( A )                                                                         \
    if ( A == NULL ) {                                                                             \
        printf( "Error Line %d File %s\n", __LINE__, __FILE__ );                                   \
        return -1;                                                                                 \
    }

BEGIN_C_DECLS

int init_fdm_2D_geom_struct( const def_int_t    *iparm,
                             const def_fixdbl_t *dparm,
                             sim_fdm_2D_geom_t  *geom_ptr );
int
init_fdm_2D_geom_struct( const def_int_t    *iparm,
                         const def_fixdbl_t *dparm,
                         sim_fdm_2D_geom_t  *geom_ptr )
{
    IS_ARY1D_NULL( iparm )
    IS_ARY1D_NULL( dparm )
    IS_ARY1D_NULL( geom_ptr )
    int ierr     = 0;
    geom_ptr->nx = iparm[IPARM_GEOM_NX];
    geom_ptr->ny = iparm[IPARM_GEOM_NY];
    geom_ptr->lx = iparm[DPARM_GEOM_LX];
    geom_ptr->ly = iparm[DPARM_GEOM_LX];
    return ierr;
}

int init_fdm_2D_time_struct( const def_int_t    *iparm,
                             const def_fixdbl_t *dparm,
                             sim_fdm_2D_time_t  *time_ptr );
int
init_fdm_2D_time_struct( const def_int_t    *iparm,
                         const def_fixdbl_t *dparm,
                         sim_fdm_2D_time_t  *time_ptr )
{
    IS_ARY1D_NULL( iparm )
    IS_ARY1D_NULL( dparm )
    IS_ARY1D_NULL( time_ptr )
    int ierr        = 0;
    time_ptr->maxit = iparm[IPARM_TIME_MAXIT];
    time_ptr->dt    = dparm[DPARM_TIME_DT];
    return ierr;
}

END_C_DECLS

#endif /* _sim_siminit_h_ */