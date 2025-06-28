/**
 *
 * @file def.h
 *
 * def a default definition of int and scalar type
 *
 * @copyright
 *
 * @version 0.0.1
 * @author zushiwuxian
 * @date 2025
 *
 **/
#ifndef _def_h_
#define _def_h_

#include "def/defconfig.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>
#include <assert.h>
#include <math.h>

#if defined( DEF_WITH_MPI )
#include <mpi.h>
typedef MPI_Comm DEF_Comm;
#else
typedef uintptr_t DEF_Comm;
#ifndef MPI_COMM_WORLD
#define MPI_COMM_WORLD 0
#endif
#endif

// #include "def/api.h"
#include "def/defdatatypes.h"
#include "sim/simdatatypes.h"
#include "sim/siminit.h"
#endif /* _def_h_ */
