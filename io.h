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
* @brief Initializes the parameters in globals.h
*
* Initializes the parameters according to the following convention:
*	- parameters[0] = i_max
*	- parameters[1] = j_max
*	- parameters[2] = a
*	- parameters[3] = b
*	- parameters[4] = Re
*	- parameters[5] = T
*/
double* init(int i_max, int j_max, double a, double b, double Re, double T);

/**
* @brief Writes grid-parameters to a file.
*/
double* output();




