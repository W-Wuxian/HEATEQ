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

int getdatafromfile( const char *restrict datafile, def_int_t *iparm, def_fixdbl_t *dparm );

int
getdatafromfile( const char *restrict datafile, def_int_t *iparm, def_fixdbl_t *dparm )
{
    if ( datafile == NULL ) {
        fputs( "NULL data file name\n", stderr );
        exit( EXIT_FAILURE );
    }
    int   ierr = 0;
    char  buffer[256];
    FILE *streamptr = { 0 };
    streamptr       = fopen( datafile, "r" );
    if ( streamptr == NULL ) {
        perror( "Error opening file" );
        return -1;
    }
    // Skip comment lines
    while ( fgets( buffer, sizeof( buffer ), streamptr ) != NULL ) {
        if ( buffer[0] != '#' ) {
            break;
        }
    }
    sscanf( buffer,
            FSCANF_INPUT_FMT_D FSCANF_INPUT_FMT_D,
            &iparm[IPARM_GEOM_NX],
            &iparm[IPARM_GEOM_NY] );

    while ( fgets( buffer, sizeof( buffer ), streamptr ) != NULL ) {
        if ( buffer[0] != '#' ) {
            break;
        }
    }
    sscanf( buffer, FSCANF_INPUT_FMT_D, &iparm[IPARM_TIME_MAXIT] );

    while ( fgets( buffer, sizeof( buffer ), streamptr ) != NULL ) {
        if ( buffer[0] != '#' ) {
            break;
        }
    }
    sscanf( buffer, FSCANF_INPUT_FMT_D, &iparm[IPARM_OPTION_SRCTERM] );

    while ( fgets( buffer, sizeof( buffer ), streamptr ) != NULL ) {
        if ( buffer[0] != '#' ) {
            break;
        }
    }
    sscanf( buffer, FSCANF_INPUT_FMT_D, &iparm[IPARM_OPTION_VERBOSE] );

    while ( fgets( buffer, sizeof( buffer ), streamptr ) != NULL ) {
        if ( buffer[0] != '#' ) {
            break;
        }
    }
    sscanf( buffer, "%lf %lf", &dparm[DPARM_GEOM_LX], &dparm[DPARM_GEOM_LY] );

    while ( fgets( buffer, sizeof( buffer ), streamptr ) != NULL ) {
        if ( buffer[0] != '#' ) {
            break;
        }
    }
    sscanf( buffer, "%lf", &dparm[DPARM_TIME_DT] );

    while ( fgets( buffer, sizeof( buffer ), streamptr ) != NULL ) {
        if ( buffer[0] != '#' ) {
            break;
        }
    }
    sscanf( buffer, "%lf", &dparm[DPARM_PHY_D] );
    fclose( streamptr );
    return ierr;
}

#endif /* _getdata_h_ */
       /**
        * @}
        */