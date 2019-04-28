/**
 * @file io.h
 * @author Hollweck, Wigg
 * @date 10 April 2019
 * @brief In- and outputs.
 */

#include <stdlib.h>
#include <stdio.h>

/**
* @brief Initializes parameters to variables given by pointers.
*/
int init(int* problem, double* f, int* i_max, int* j_max, double* a, double* b, double* Re, double* T, double* g_x, double *g_y, double* tau, double* omega, double* epsilon, int* max_it, int* n_print);

/**
 * @brief Writes grid values to disk.
 * 
 * @param i_max Grid size in x-direction.
 * @param j_max Grid size in y-direction.
 * @param u Velocity grid in x-direction.
 * @param v Velocity grid in y-direction.
 * @param p Pressure grid.
 * @param t Current time of integration.
 * @param a Physical size of grid in x-direction.
 * @param b Physical size of grid in y-direction.
 * @param prefix Filename prefix used for output files.
 * 
 * @return 0 on success.
 */
int output(int i_max, int j_max, double** u, double** v, double** p, double t, double a, double b, const char* prefix);

/**
 * @brief Gives greatest entry of a matrix.
 *
 * @param i_max Size of matrix in x-direction.
 * @param j_max Size of matrix in y-direction.
 * @param u Matrix as pointer to pointer.
 * 
 * @return Greatest entry of u.
 */
double max_mat(int i_max, int j_max, double** u);


/**
 * @brief Returns smallest value of arbitrarily many values.
 * 
 * @param num Number of arguments.
 * @param ... Arbitrary number of arguments. Should be double. The function will return the smallest of the values.
 * 
 * @return Smallest of all values.
 */

double n_min(int num, ...);