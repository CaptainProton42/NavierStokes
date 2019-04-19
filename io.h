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
int output(int i_max, int j_max, double** u, double** v, double** p, const char* prefix);

/**
* @brief Gives smallest entry of a vector.
*/
double smallest_number(int i_max, double* u);
/**
* @brief Gives greatest entry of an array.
*/
double biggest_number(int i_max, int j_max, double** u);