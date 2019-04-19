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

#include <math.h>
#include <stdio.h>


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

    double** F;
    double** G;
    double** res;
    double** RHS;

    double* conditions;
    conditions = (double*) calloc(3, sizeof(double*));

    int i_max, j_max; // Dimensions of the grid.
    double a, b; // Sizes of the grid.
    double Re; // Reynolds number;
    double delta_t, delta_x, delta_y; // Step sizes.
    double T; // Max time.
    double g_x;
    double g_y;
    double tau;

	init(&i_max, &j_max, &a, &b, &Re, &T, &g_x, &g_y, &tau);
    printf("Initialized!\n");

    delta_x = a / i_max;
    delta_y = b / j_max;


    allocate_memory(&u, &v, &p, &res, &RHS, &F, &G, i_max, j_max);

    printf("Memory allocated.\n");

    // Steps.
    double gamma = 0.1;
    double t = 0;
    int i, j;
    int n = 0;

    while (t < T) {
        printf("%.5f / %.5f\n---------------------\n", t, T);

    	// Adaptive stepsize and weight factor for Donor-Cell
        double u_max = max_mat(i_max, j_max, u);
        double v_max = max_mat(i_max, j_max, v);

    	delta_t = tau * n_min(3, Re / 2.0 / ( 1.0 / delta_x / delta_x + 1.0 / delta_y / delta_y ), delta_x / fabs(u_max), delta_y / fabs(v_max));
        gamma = fmax(u_max * delta_t / delta_x, v_max * delta_t / delta_y);

        // Set boundary conditions.
        set_noslip(i_max, j_max, u, v, LEFT);
        set_noslip(i_max, j_max, u, v, TOP);
        set_noslip(i_max, j_max, u, v, BOTTOM);
        set_inflow(i_max, j_max, u, v, RIGHT, 0.0, 10.0);

        printf("Conditions set!\n");

        // Calculate F and G.
        FG(F, G, u, v, i_max, j_max, Re, g_x, g_y, delta_t, delta_x, delta_y, gamma);

        printf("F, G calculated!\n");

        // RHS of Poisson equation.
        for (i = 1; i <= i_max; i++ ) {
            for (j = 1; j <= j_max; j++) {
                RHS[i][j] = 1.0 / delta_t * ((F[i][j] - F[i-1][j])/delta_x + (G[i][j] - G[i][j-1])/delta_y);
            }
        }

        printf("RHS calculated!\n");

        SOR(p, i_max, j_max, delta_x, delta_y, res, RHS, 1.7, 0.001);

        printf("SOR complete!\n");

        // Update velocities.
        for (i = 1; i <= i_max; i++ ) {
            for (j = 1; j <= j_max; j++) {
                if (i <= i_max - 1) u[i][j] = F[i][j] - delta_t * dp_dx(p, i, j, delta_x);
                if (j <= j_max - 1) v[i][j] = G[i][j] - delta_t * dp_dy(p, i, j, delta_y);
            }
        }

        printf("Velocities updatet!\n");
        char out_prefix[12];
        sprintf(out_prefix, "out/%d", n);
        output(i_max, j_max, u, v, p, out_prefix);

        t += delta_t;
        n++;
    }

    free_memory(&u, &v, &p, &res, &RHS, &F, &G);
    free(conditions);
    return 0;
}