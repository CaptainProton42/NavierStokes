/**
 * @file io.h
 * @author Hollweck, Wigg
 * @date 10 April 2019
 * @brief In- and outputs.
 */

#include <stdlib.h>
#include <stdio.h>

/**
* @brief Initializes given parameters.
*/
int init(int* i_max, int* j_max, double* a, double* b, double* Re, double* T, double* g_x, double *g_y, double* tau);

/**
* @brief Writes grid values to disk.
*/
int output(int i_max, int j_max, double** u, double** v, double** p, double t, double a, double b, const char* prefix);

/**
* @brief Gives greatest entry of an array.
*/
double max_mat(int i_max, int j_max, double** u);

double n_min(int num, ...);