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
    printf( "%zu \n", def_size_of( type ) );

    def_int_t    iparm[IPARM_SIZE];
    def_fixdbl_t dparm[DPARM_SIZE];
    ierr = getdatafromfile( "./DATA.dat", &iparm[0], &dparm[0] );
    printf( "%d " PRINTF_INPUT_FMT_D " " PRINTF_INPUT_FMT_D " " PRINTF_INPUT_FMT_D
            " " PRINTF_INPUT_FMT_D " " PRINTF_INPUT_FMT_D "\n",
            IPARM_SIZE,
            iparm[0],
            iparm[1],
            iparm[2],
            iparm[3],
            iparm[4] );
    printf( "%d\n", DPARM_SIZE );
    //    getdatafromfile return ierr;
    return ierr;
}