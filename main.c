#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "def.h"

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
    def_coeftype_t type = DefDouble;
    printf( "%zu \n", def_size_of( type ) );
    return ierr;
}