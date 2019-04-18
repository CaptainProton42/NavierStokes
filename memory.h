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
 * @brief Allocate memory for all grids used during integration.
 * 
 * @param u Velocity lattice x-component.
 * @param v Velociry lattice y-component.
 * @param p pressure lattice.
 * @param residuum grid.
 * @param grid storing RHS of poission equation.
 * @param i_max Lattice dimension in x-direction.
 * @param j_max Lattice dimension in y-direction.
 * @return 0 on finish.
 */

int allocate_memory(double*** u, double*** v, double*** p, double*** res, double*** RHS, double*** F, double*** G, int i_max, int j_max);

/**
 * @brief Free memory of all grids used during integration.
 * @brief Allocate memory for all grids used during integration.
 * 
 * @param u Velocity lattice x-component.
 * @param v Velociry lattice y-component.
 * @param p pressure lattice.
 * @param residuum grid.
 * @param grid storing RHS of poission equation.
 * @param i_max Lattice dimension in x-direction.
 * @param j_max Lattice dimension in y-direction.
 * @return 0 on finish.
 */

int free_memory(double*** u, double*** v, double*** p, double*** res, double*** RHS, double*** F, double*** G);

#endif