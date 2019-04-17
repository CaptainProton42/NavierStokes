/**
 * @file main.c
 * @author Hollweck, Wigg
 * @date 10 April 2019
 * @brief Main file.
 *
 * Here typically goes a more extensive explanation of what the header
 * defines. Doxygens tags are words preceeded by either a backslash @\
 * or by an at symbol @@.
 * @see http://www.stack.nl/~dimitri/doxygen/docblocks.html
 * @see http://www.stack.nl/~dimitri/doxygen/commands.html
 */

#include "memory.h"
#include "io.h"
#include "integration.h"
#include "boundaries.h"
#include "math.h"


/**
 * @brief Main function.
 * 
 * This is the main function.
 * @return 0 on exit.
 */

int main()
{
	double** u;
	double** v;
	double** p;

	init(i_max, j_max, a, b, Re, T);
	output(&u,&v);
    return 0;
}