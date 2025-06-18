/**
 * @file defdatatypes.h
 *
 * @copyright 2025 something
 *
 * @version 0.0.1
 * @author ZushiWuxian
 *
 *
 **/
#ifndef _def_defdatatypes_h_
#define _def_defdatatypes_h_

#include <inttypes.h>
#include "defconfig.h"

BEGIN_C_DECLS

/**
 * @addtogroup defdatatypes
 * @{
 *   @def DEF_MPI_INT
 *   @brief The MPI type associated to def_int_t
 *
 *   @def DEF_INT_MAX
 *   @brief The maximum def_int_t value
 *
 *   @typedef def_int_t
 *   @brief The main integer datatype used in def objects
 *
 *   @typedef def_uint_t
 *   @brief The main unsigned integer datatype used in def objects
 *
 *   @typedef def_complex64_t
 *   @brief The double complex arithmetic datatype
 *
 *   @typedef def_complex32_t
 *   @brief The real complex arithmetic datatype
 */

#if defined( DEF_INT64 )

typedef int64_t  def_int_t;
typedef uint64_t def_uint_t;
#define DEF_MPI_INT MPI_INTEGER8
#define DEF_INT_MAX INT64_MAX

#elif defined( DEF_INT32 )

typedef int32_t  def_int_t;
typedef uint32_t def_uint_t;
#define DEF_MPI_INT MPI_INTEGER8
#define DEF_INT_MAX INT32_MAX

#elif defined( DEF_LONG )

typedef long          def_int_t;
typedef unsigned long def_uint_t;
#define DEF_MPI_INT MPI_LONG
#define DEF_INT_MAX LONG_MAX

#else

typedef int          def_int_t;
typedef unsigned int def_uint_t;
#define DEF_MPI_INT MPI_INT
#define DEF_INT_MAX INT_MAX

#endif /* DEF_INT64 */
/**
 *@}
 */

/**
 *******************************************************************************
 *
 * @ingroup defdatatypes
 * @brief Internal function to compute min(a,b)
 *
 *******************************************************************************
 *
 * @param[in] a
 * @param[in] b
 *
 *******************************************************************************
 *
 * @return min( a, b )
 *
 ********************************************************************************/
static inline def_int_t
def_imin( def_int_t a, def_int_t b )
{
    return ( a < b ) ? a : b;
}

/**
 *******************************************************************************
 *
 * @ingroup defdatatypes
 * @brief Internal function to compute max(a,b)
 *
 *******************************************************************************
 *
 * @param[in] a
 * @param[in] b
 *
 *******************************************************************************
 *
 * @return max( a, b )
 *
 ********************************************************************************/
static inline def_int_t
def_imax( def_int_t a, def_int_t b )
{
    return ( a > b ) ? a : b;
}

/**
 *******************************************************************************
 *
 * @ingroup defdatatypes
 * @brief Internal function to compute ceil(a,b) the ceiling value of a/b
 *
 *******************************************************************************
 *
 * @param[in] a
 * @param[in] b
 *
 *******************************************************************************
 *
 * @return ceil( a, b )
 *
 ********************************************************************************/
static inline def_int_t
def_iceil( def_int_t a, def_int_t b )
{
    return ( a + b - 1 ) / b;
}

/**
 *******************************************************************************
 *
 * @ingroup defdatatypes
 * @brief Compute trailing zeros.
 *
 *******************************************************************************
 *
 * @param[in] n
 *          Integer to compute trailing zeros.
 *
 *******************************************************************************
 *
 * @param[inout] count
 *          The number of trailing zeros.
 *
 *******************************************************************************/
static inline void
def_trailingzero( def_int_t n, def_int_t *count )
{
    *count = 0;
    while ( n > 0 && ( n & 1 ) == 0 ) {
        *count += 1;
        n = n >> 1;
    }
}

#ifndef NAN
#define NAN ( 0. / 0. )
#endif

/**
 * @ingroup defdatatypes
 * @brief Double and Float datatype that is not converted through precision generator functions
 */
typedef double def_fixdbl_t;
typedef float  def_fixflt_t;

/**
 * @ingroup defdatatypes
 * @brief Double anf Float datatype that should be used in the local subs.py like the following:
 * ('int', 'def_float_t', 'def_double_t', 'def_complex32_t', 'def_complex64_t' )
 */
typedef double def_double_t;
typedef float  def_float_t;

/**
 * Compiler numbers (Extracted form PaRSEC project)
 **/
#if defined( _MSC_VER ) && !defined( __INTEL_COMPILER )
/* Windows and non-Intel compiler */
#include <complex>
typedef std::complex<float>  def_complex32_t;
typedef std::complex<double> def_complex64_t;
#else
typedef float _Complex def_complex32_t;
typedef double _Complex def_complex64_t;
#endif

#if !defined( __cplusplus ) && defined( HAVE_COMPLES_H )
#include <complex.h>
#else

#ifdef __cplusplus
extern "C" {
#endif

/**
 * These declaration will not clash with C++ provides because
 * the names in C++ are name-mangled.
 */

extern double cabs( def_complex64_t z );
extern double creal( def_complex64_t z );
extern double cimag( def_complex64_t z );

extern float cabsf( def_complex32_t z );
extern float crealf( def_complex32_t z );
extern float cimagf( def_complex32_t z );

extern def_complex64_t conj( def_complex64_t z );
extern def_complex64_t csqrt( def_complex64_t z );

extern def_complex32_t conjf( def_complex32_t z );
extern def_complex32_t csqrtf( def_complex32_t z );

#ifdef __cplusplus
}
#endif

#endif /* HAVE_COMPLEX_H */

#define DEF_MPI_COMPLEX64 MPI_C_DOUBLE_COMPLEX
#define DEF_MPI_COMPLEX32 MPI_C_FLOAT_COMPLEX
#define DEF_MPI_DOUBLE MPI_DOUBLE
#define DEF_MPI_FLOAT MPI_FLOAT

/**
 * @ingroup defdatatypes
 * @brief Arithmetic types
 *
 */
typedef enum def_coeftype_e {
    DefPattern   = 0,
    DefFloat     = 2,
    DefDouble    = 3,
    DefComplex32 = 4,
    DefComplex64 = 5
} def_coeftype_t;

/**
 *******************************************************************************
 *
 * @ingroup defdatatypes
 * @brief Compute sizeof type.
 *
 *******************************************************************************
 *
 * @param[in] type
 *          enum pointing out the type of float (float, double, complex32 or complex64)
 *
 *******************************************************************************
 *
 * @return def_size_of( type )
 *          sizeof( input type )
 *
 *******************************************************************************/
static inline size_t
def_size_of( def_coeftype_t type )
{
    switch ( type ) {
        case DefFloat:
            return sizeof( float );
        case DefDouble:
            return sizeof( double );
        case DefComplex32:
            return 2 * sizeof( float );
        case DefComplex64:
            return 2 * sizeof( double );
        default:
            fprintf( stderr, "def_size_of: invalid type parameter\n" );
            assert( 0 );
            return sizeof( double );
    }
}

END_C_DECLS

#endif /* _def_defdatatypes_h_ */
