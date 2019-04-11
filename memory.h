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

/**
 * @brief Allocate memory for the three displaced lattices.
 * 
 * @param u Velocity lattice x-component.
 * @param v Velociry lattice y-component.
 * @param p pressure lattice.
 * @param i_max Lattice dimension in x-direction.
 * @param j_max Lattice dimension in y-direction.
 * @return 0 on finish.
 */

extern int allocate_memory(double*** u, double*** v, double*** p, int i_max, int j_max);

#endif