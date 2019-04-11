/**
 * @file memory.h
 * @author Hollweck, Wigg
 * @date 10 April 2019
 * @brief Memory management.
 */

#ifndef _MEMORY_H
#define _MEMORY_H

#include <stdlib.h>
#include <stdio.h>

extern double** u; ///< Velocity lattice in x direction.
extern double** v; ///< Velocity lattice in y direction.
extern double** p; ///< Pressure lattice.


/**
 * @brief Allocate memory for the three displaced lattices.
 * 
 * @param i_max Lattice dimension in x-direction.
 * @param j_max Lattice dimension in y-direction.
 * @return 0 on finish.
 */

extern int allocate_memory(int i_max, int j_max);

#endif