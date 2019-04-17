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

    int i_max, j_max; // Dimensions of the grid.
    double a, b; // Sizes of the grid.
    double Re; // Reynolds number;
    double delta_t, delta_x, delta_y; // Step sizes.
    double T; // Max time.

	init(&i_max, &j_max, &a, &b, &Re, &T, &delta_x, &delta_y);
    allocate_memory(&u, &v, &p, i_max, j_max);
    printf("Setting boundary conditions...\n");
    set_noslip(i_max, j_max, u, v, LEFT);
    printf("Left side set!\n");
    set_noslip(i_max, j_max, u, v, RIGHT);
    printf("Right side set!\n");
    set_noslip(i_max, j_max, u, v, BOTTOM);
    printf("Bottom side set!\n");
    set_inflow(i_max, j_max, u, v, TOP, 0, 1);
    printf("Top side set!\n");

	output(i_max, j_max, u, v, p);
    return 0;
}