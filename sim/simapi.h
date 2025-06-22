#ifndef _sim_simapi_h_
#define _sim_simapi_h_

#include "def.h"

#define Sim2DFDMGeomLX ( (def_fixdbl_t)1 )
#define Sim2DFDMGeomLY ( (def_fixdbl_t)1 )
#define Sim2DFDMPhyD ( (def_fixdbl_t)1 )
#define Sim2DFDMTimeDT ( (def_fixdbl_t)1 )
#define Sim2DFDMGeomNX ( (def_int_t)1 )
#define Sim2DFDMGeomNY ( (def_int_t)1 )
#define Sim2DFDMTimeMAXIT ( (def_int_t)1 )
#define Sim2DFDMOptionVERBOSE ( (def_int_t)1 )
#define Sim2DFDMOptionSrcTERM ( (def_int_t)1 )

BEGIN_C_DECLS

/**
 * @brief Integer parameters
 */
typedef enum sim_2d_fdm_iparm_e {
    /* Geometry NX */
    IPARM_GEOM_NX, /**< Geommetry Number of points along X axis: NX ; Default: Sim2DFDMNX      */
    /* Geometry NY */
    IPARM_GEOM_NY, /**< Geommetry Number of points along Y axis: NY Default: Sim2DFDMNY      */
    /* Time MAXIT */
    IPARM_TIME_MAXIT, /**< Time Max iteration number: MAXIT Default: Sim2DFDMTimeMAXIT     */
    /* Option SOURCETERM */
    IPARM_OPTION_SRCTERM, /**< Option Select hard-coded source term Default: Sim2DFDMOptionSrcTERM
                           */
    /* Option VERBOSE */
    IPARM_OPTION_VERBOSE, /**< Option Display Solution, Errors... Default: Sim2DFDMOptionVERBOSE */
    IPARM_SIZE
} sim_2d_fdm_iparm_t;

/**
 * @brief Float parameters
 */
typedef enum sim_dparm_e {
    /* Geometry LX */
    DPARM_GEOM_LX, /**< Geommetry Length along X axis: LX ; Default: Sim2DFDMGeomLX  */
    /* Geometry LY */
    DPARM_GEOM_LY, /**< Geommetry Length along Y axis: LY ; Default: Sim2DFDMGeomLY  */
    /* Time DT */
    DPARM_TIME_DT, /**< Time step DT ; Default: Sim2DFDMTimeDT        */
    /* Physic D */
    DPARM_PHY_D, /**< Physic Thermal diffusivity D ; Default: Sim2DFDMPhyD        */
    DPARM_SIZE
} sim_dparm_t;

END_C_DECLS

#endif /* _sim_simapi_h_ */