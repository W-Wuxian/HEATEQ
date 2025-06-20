#ifndef _sim_simapi_h_
#define _sim_simapi_h_

#include "def.h"

#define Sim2DFDMGeomLX 1
#define Sim2DFDMGeomLY 1
#define Sim2DFDMPhyD 1
#define Sim2DFDMNX 1
#define Sim2DFDMNY1

BEGIN_C_DECLS

/**
 * @brief Integer parameters
 */
typedef enum sim_2d_fdm_iparm_e {
    /* Geometry LX */
    IPARM_GEOM_LX, /**< GEOM LX Default: Sim2DFDMGeomLX  */
    /* Geometry LY */
    IPARM_GEOM_LY, /**< GEOM LY Default: Sim2DFDMGeomLY  */
    /* Physic D */
    IPARM_PHY_D, /**< PHY D Default: Sim2DFDMPhyD        */
    /* Geometry NX */
    IPARM_GEOM_NX, /**< GEOM NX Default: Sim2DFDMNX      */
    /* Geometry NY */
    IPARM_GEOM_NY, /**< GEOM NY Default: Sim2DFDMNY      */
    IPARM_SIZE
} sim_2d_fdm_iparm_t;

/**
 * @brief Float parameters
 */
typedef enum sim_dparm_e {
    DPARM_FILL_IN,     /**< Maximum memory (-DMEMORY_USAGE)     Default: - OUT */
    DPARM_LSS_TIME,    /**< Time for subtask LSS (wallclock)    Default: - OUT */
    DPARM_SKETCH_TIME, /**< Time for subtask SKECTH (wallclock) Default: - OUT */
    DPARM_SIZE
} sim_dparm_t;

END_C_DECLS

#endif /* _sim_simapi_h_ */