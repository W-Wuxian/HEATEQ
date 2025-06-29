#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include "def.h"
#include "getdata.h"

int
main()
{
    int ierr = 0;
    printf( "%s\n", "Hello World!" );
#if DEF_INT64 == 1
    def_int_t  a = 1;
    def_uint_t b = 1;
    printf( "%" PRId64 "\n", a );
    printf( "%" PRIu64 "\n", b );
#endif
#ifdef DEF_INT64
    printf( "DEF_INT64 is defined as: %d\n", DEF_INT64 );
#else
    printf( "DEF_INT64 is not defined.\n" );
#endif
#ifdef DEFAULT_INT
    printf( "DEFAULT_INT is defined\n" );
#else
    printf( "DEFAULT_INT is not defined.\n" );
#endif
    def_coeftype_t type = DefDouble;
    printf( "Size of Double %zu \n", def_size_of( type ) );

    // def_int_t    iparm[IPARM_SIZE];
    // def_fixdbl_t dparm[DPARM_SIZE];
    CREATE_IPARM( iparm );
    CREATE_DPARM( dparm );
    ierr = getdatafromfile( "./DATA.dat", &iparm[0], &dparm[0] );
    printf( "iparm lenght %d\nNX " PRINTF_INPUT_FMT_D "\nNY " PRINTF_INPUT_FMT_D
            "\nMAXIT " PRINTF_INPUT_FMT_D "\nSRCTERM " PRINTF_INPUT_FMT_D
            "\nVERBOSE " PRINTF_INPUT_FMT_D "\n",
            IPARM_SIZE,
            iparm[0],
            iparm[1],
            iparm[2],
            iparm[3],
            iparm[4] );
    printf( "dparm lenght %d\nLX %lf\nLY %lf\nDT %lf\nD %lf\n",
            DPARM_SIZE,
            dparm[0],
            dparm[1],
            dparm[2],
            dparm[3] );
    sim_fdm_2D_parameter_t fdm2Dparam_sim1 = INIT_SIM_FDM2D_PARM( iparm, dparm );
    printf( "parameter iparm lenght %d\nNX " PRINTF_INPUT_FMT_D "\nNY " PRINTF_INPUT_FMT_D
            "\nMAXIT " PRINTF_INPUT_FMT_D "\nSRCTERM " PRINTF_INPUT_FMT_D
            "\nVERBOSE " PRINTF_INPUT_FMT_D "\n",
            IPARM_SIZE,
            fdm2Dparam_sim1.iparm[0],
            fdm2Dparam_sim1.iparm[1],
            fdm2Dparam_sim1.iparm[2],
            fdm2Dparam_sim1.iparm[3],
            fdm2Dparam_sim1.iparm[4] );
    printf( "parameter dparm lenght %d\nLX %lf\nLY %lf\nDT %lf\nD %lf\n",
            DPARM_SIZE,
            fdm2Dparam_sim1.dparm[0],
            fdm2Dparam_sim1.dparm[1],
            fdm2Dparam_sim1.dparm[2],
            fdm2Dparam_sim1.dparm[3] );
    sim_fdm_2D_geom_t   fdm2Dgeom_sim1   = INIT_SIM_FDM2D_GEOM();
    sim_fdm_2D_time_t   fdm2Dtime_sim1   = INIT_SIM_FDM2D_TIME();
    sim_fdm_2D_phy_t    fdm2Dphy_sim1    = INIT_SIM_FDM2D_PHY();
    sim_fdm_2D_option_t fdm2Doption_sim1 = INIT_SIM_FDM2D_OPTION();
    printf( "Geom \nNX " PRINTF_INPUT_FMT_D "\nNY " PRINTF_INPUT_FMT_D
            "\nLX %lf\nLY %lf\nDX %lf\nDY %lf\n",
            fdm2Dgeom_sim1.nx,
            fdm2Dgeom_sim1.ny,
            fdm2Dgeom_sim1.lx,
            fdm2Dgeom_sim1.ly,
            fdm2Dgeom_sim1.dx,
            fdm2Dgeom_sim1.dy );
    printf(
        "Time \nMAXIT " PRINTF_INPUT_FMT_D "\nDT %lf\n", fdm2Dtime_sim1.maxit, fdm2Dtime_sim1.dt );
    printf( "Physic \nDiffusion D %lf\n", fdm2Dphy_sim1.d );
    printf( "Options \nVERBOSE " PRINTF_INPUT_FMT_D "\nSOURCE TERM " PRINTF_INPUT_FMT_D "\n",
            fdm2Doption_sim1.verbose,
            fdm2Doption_sim1.srcterm );
    def_int_t    points_sim1[fdm2Dgeom_sim1.nx * fdm2Dgeom_sim1.nx];
    def_fixdbl_t Xi_sim1[fdm2Dgeom_sim1.nx];
    def_fixdbl_t Yj_sim1[fdm2Dgeom_sim1.ny];
    for ( def_int_t i = 0; i < fdm2Dgeom_sim1.nx; ++i ) {
        Xi_sim1[0] = (def_fixdbl_t)i * fdm2Dgeom_sim1.dx;
    }
    for ( def_int_t i = 0; i < fdm2Dgeom_sim1.ny; ++i ) {
        Yj_sim1[0] = (def_fixdbl_t)i * fdm2Dgeom_sim1.dy;
    }
    sim_gridorder_t gridorder_sim1 = GRID_ORDER_PIJ;
    def_int_t       k              = 0;
    for ( def_int_t i = 0; i < fdm2Dgeom_sim1.nx; ++i ) {
        k = i * fdm2Dgeom_sim1.ny;
        for ( def_int_t j = 0; j < fdm2Dgeom_sim1.ny; ++j ) {
            points_sim1[k + j] = k + j;
            printf( "i " PRINTF_INPUT_FMT_D " j " PRINTF_INPUT_FMT_D " PIJ " PRINTF_INPUT_FMT_D
                    "\n",
                    i,
                    j,
                    points_sim1[k + j] );
        }
    }

    // sim_fdm_2D_grid_t fdm2Dgrid_sim1;
    // fdm2Dgrid_sim1.point;
    return ierr;
}