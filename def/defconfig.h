/**
 *
 * @file def_defconfig.h.in
 *
 * DEF configuration parameters
 *
 * @copyright
 *
 * @version 0.0.1
 * @author zushiwuxian
 * @date
 *
 **/

#ifndef _def_defconfig_h_
#define _def_defconfig_h_

#if defined( WIN32 ) || defined( _WIN32 )
#define RKT_OS_WINDOWS 1
#endif

/*
 * BEGIN_C_DECLS should be used at the beginning of your declarations,
 * so that C++ compilers don't mangle their names.  Use END_C_DECLS at
 * the end of C declarations.
 */
#undef BEGIN_C_DECLS
#undef END_C_DECLS
#if defined( c_plusplus ) || defined( __cplusplus )
#define BEGIN_C_DECLS extern "C" {
#define END_C_DECLS }
#else
#define BEGIN_C_DECLS /* empty */
#define END_C_DECLS   /* empty */
#endif

#endif /* _def_defconfig_h_ */