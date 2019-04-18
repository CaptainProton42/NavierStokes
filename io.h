/**
 * @file io.h
 * @author Hollweck, Wigg
 * @date 10 April 2019
 * @brief In- and outputs.
 *
 * Here typically goes a more extensive explanation of what the header
 * defines. Doxygens tags are words preceeded by either a backslash @\
 * or by an at symbol @@.
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 */

#include <stdlib.h>
#include <stdio.h>

/**
* @brief Initializes given parameters.
*/
int init(int* i_max, int* j_max, double* a, double* b, double* Re, double* T, double* delta_x, double* delta_y);

/**
* @brief Writes grid values to disk.
*/
int output(int i_max, int j_max, double** u, double** v, double** p);

/**
* @brief Gives smallest entry of a vector.
*/
double smallest_number(int i_max, double* u);
/**
* @brief Gives greatest entry of an array.
*/
double biggest_number(int i_max, int j_max, double** u);