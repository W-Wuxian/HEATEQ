#ifndef _sim_simdatatypes_h_
#define _sim_simdatatypes_h_

#include "def.h"

//        Y,j
//        ^
//        |
//        |
//        |
//        |
//        |
//        |-----------------> X,i
//       /
//      /
//     /
//    /
//   /
//  /
// Z,k

BEGIN_C_DECLS

struct sim_fdm_2D_parameter_s;
typedef struct sim_fdm_2D_parameter_s {
    def_int_t    *iparm;
    def_fixdbl_t *dparm;
} sim_fdm_2D_parameter_t;

struct sim_fdm_2D_geom_s;
typedef struct sim_fdm_2D_geom_s {
    def_int_t    nx; /**< Global number of vertices along X axis */
    def_int_t    ny; /**< Global number of vertices along Y axis */
    def_fixdbl_t lx; /**< Length along X axis */
    def_fixdbl_t ly; /**< Length along Y axis */
} sim_fdm_2D_geom_t;

struct sim_fdm_2D_time_s;
typedef struct sim_fdm_2D_time_s {
    def_int_t    maxit; /**< Global number of time steps */
    def_fixdbl_t dt;    /**< Time step (sec) */
} sim_fdm_2D_time_t;

struct sim_fdm_2D_phy_s;
typedef struct sim_fdm_2D_phy_s {
    def_fixdbl_t d; /**< Thermal diffusivity  m²/s */
} sim_fdm_2D_phy_t;

struct sim_fdm_2D_option_s;
typedef struct sim_fdm_2D_option_s {
    def_int_t verbose; /**< Option Display Solutions, Errors (1) or not (0) */
    def_int_t srcterm; /**< Option Select hard-Coded source term cases (1, 2 or 3) */
} sim_fdm_2D_option_t;

struct sim_fdm_2D_grid_s;
typedef struct sim_fdm_2D_grid_s {
    def_fixdbl_t *point; /**< point with coordinates (x,y) */
    def_fixdbl_t *crdx;  /**< x coordinate along X axis */
    def_fixdbl_t *crdy;  /**< y coordinate along Y axis */
} sim_fdm_2D_grid_t;

// struct sim_fdm_2D_grid_s;
// typedef struct sim_fdm_2D_grid_s {
//     def_fixdbl_t *glox; /**< Global List of X_{i} point along X axis */
//     def_fixdbl_t *gloy; /**< Global List of Y_{j} point along Y axis */
//     sim_fdm_2D_grid_t
//         *glopxy; /**< Global List of P_{ij}=P_{k} point i=1,nx-1 j=1,ny-1 with k=(i-1)(ny-2)j
//                   */
//     sim_fdm_2D_grid_t
//         *glopyx; /**< Global List of P_{ji} point j=1,ny-1 i=1,nx-1 with k=(j-1)(nx-2)i */
// } sim_fdm_2D_grid_t;

struct sim_fdm_2D_struct_s;
typedef struct sim_fdm_2D_struct_s {
    sim_fdm_2D_option_t *option;
    sim_fdm_2D_phy_t    *physic_setting;
    sim_fdm_2D_time_t   *time_setting;
    sim_fdm_2D_geom_t   *geom_setting;
    sim_fdm_2D_grid_t  **global_grid;
    // Can be P_{ij}  order w/ i=1,nx-1 j=1,ny-1 with k=(i-1)(ny-2)j
    // Or P_{ji} oerder w/ j=1,ny-1 i=1,nx-1 with k=(j-1)(nx-2)i
    // Or P_{Hilbertian distrib} ?
} sim_fdm_2D_struct_t;

END_C_DECLS

#endif /* _sim_simdatatypes_h_ */