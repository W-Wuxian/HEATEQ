/**
 * @file getdata.h
 *
 * @copyright 2025 something
 *
 * @version 0.0.1
 * @author ZushiWuxian
 *
 * @addtogroup getdata
 * @{
 *
 **/
#ifndef _getdata_h_
#define _getdata_h_

#include "def.h"

#define FSCANF_FAILED_MSG( a, b )                                                                  \
    if ( a != b ) {                                                                                \
        fputs( "Failed to fscanf data from file!\n", stderr );                                     \
        printf( "line number %d in file %s\n", __LINE__, __FILE__ );                               \
        printf( "a %d b %d\n", a, b );                                                             \
        exit( EXIT_FAILURE );                                                                      \
    }

#define SKIP_DATA_HEADER                                                                           \
    ierr = fscanf( streamptr, "%s", dataheader );                                                  \
    printf( "line number %d in file %s\n", __LINE__, __FILE__ );                                   \
    printf( "ierr %d SKIP_DATA_HEADER %s\n", ierr, dataheader );                                   \
    FSCANF_FAILED_MSG( ierr, 1 );

#define FGETS_FAILED_MSG( a )                                                                      \
    {                                                                                              \
        if ( a == NULL ) {                                                                         \
            fputs( "Failed to fgets data from file!\n", stderr );                                  \
            printf( "line number %d in file %s\n", __LINE__, __FILE__ );                           \
            exit( EXIT_FAILURE );                                                                  \
        }                                                                                          \
    }                                                                                              \
    while ( 0 )

#define SKIP_DATA_HEADER_FGETS                                                                     \
    printf( "line number %d in file %s\n", __LINE__, __FILE__ );                                   \
    FGETS_FAILED_MSG( fgets( dataheader, sizeof( dataheader ), streamptr ) );                      \
    printf( "SKIP_DATA_HEADER_FGETS %s\n", dataheader );

int getdatafromfile( const char *restrict datafile, def_int_t *iparm, def_fixdbl_t *dparm );

int
getdatafromfile( const char *restrict datafile, def_int_t *iparm, def_fixdbl_t *dparm )
{
    int   ierr = 0;
    char  dataheader[255];
    FILE *streamptr = { 0 };
    if ( datafile == NULL ) {
        fputs( "NULL data file name\n", stderr );
        exit( EXIT_FAILURE );
    }
    streamptr = fopen( datafile, "r" );
    if ( streamptr == NULL ) {
        perror( "error opening file\n" );
        exit( EXIT_FAILURE );
    }
    else {
        SKIP_DATA_HEADER_FGETS
        SKIP_DATA_HEADER_FGETS
        ierr = fscanf( streamptr,
                       FSCANF_INPUT_FMT_D FSCANF_INPUT_FMT_D,
                       &iparm[IPARM_GEOM_NX],
                       &iparm[IPARM_GEOM_NY] );
        printf( " %ld %ld ierr=%d\n", iparm[IPARM_GEOM_NX], iparm[IPARM_GEOM_NY], ierr );
        FSCANF_FAILED_MSG( ierr, 2 );
        SKIP_DATA_HEADER_FGETS
        ierr = fscanf( streamptr, "%ld", &iparm[IPARM_TIME_MAXIT] );
        printf( " %ld \n", iparm[IPARM_TIME_MAXIT] );
        FSCANF_FAILED_MSG( ierr, 1 );
        SKIP_DATA_HEADER_FGETS
        ierr = fscanf( streamptr, FSCANF_INPUT_FMT_D, &iparm[IPARM_OPTION_SRCTERM] );
        FSCANF_FAILED_MSG( ierr, 1 );
        SKIP_DATA_HEADER_FGETS
        ierr = fscanf( streamptr, FSCANF_INPUT_FMT_D, &iparm[IPARM_OPTION_VERBOSE] );
        FSCANF_FAILED_MSG( ierr, 1 );
        SKIP_DATA_HEADER_FGETS
        SKIP_DATA_HEADER_FGETS
        ierr = fscanf( streamptr, "%lf %lf", &dparm[DPARM_GEOM_LX], &dparm[DPARM_GEOM_LY] );
        FSCANF_FAILED_MSG( ierr, 2 );
        SKIP_DATA_HEADER_FGETS
        ierr = fscanf( streamptr, "%lf", &dparm[DPARM_TIME_DT] );
        FSCANF_FAILED_MSG( ierr, 1 );
        SKIP_DATA_HEADER_FGETS
        ierr = fscanf( streamptr, "%lf", &dparm[DPARM_PHY_D] );
        FSCANF_FAILED_MSG( ierr, 1 );
    }
    fclose( streamptr );
    return ierr;
}

#endif /* _getdata_h_ */
       /**
        * @}
        */