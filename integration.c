#include <stdlib.h>
#include <stdio.h>
#include <math.h> 

#include "integration.h"

double du2_dx(double** u, double** v, int i, int j, double delta_x, double gamma) {
    double stencil1 = 0.5 * (u[i][j] + u[i+1][j]);
    double stencil2 = 0.5 * (u[i-1][j] + u[i][j]);

    double stencil3 = fabs(stencil1) * 0.5 * (u[i][j] - u[i+1][j]);
    double stencil4 = fabs(stencil2) * 0.5 * (u[i-1][j] - u[i][j]);

    return 1/delta_x * (stencil1*stencil1 - stencil2*stencil2) + gamma / delta_x * (stencil3 - stencil4);
}

double duv_dy(double** u, double** v, int i, int j, double delta_y, double gamma) {
    double stencil1 = 0.5 * (v[i][j] + v[i+1][j]);
    double stencil2 = 0.5 * (v[i][j-1] + v[i+1][j-1]);

    double stencil3 = stencil1 * 0.5 * (u[i][j] + u[i][j+1]);
    double stencil4 = stencil2 * 0.5 * (u[i][j-1] + u[i][j]);

    double stencil5 = fabs(stencil1) * 0.5 * (u[i][j] - u[i][j+1]);
    double stencil6 = fabs(stencil2) * 0.5 * (u[i][j-1] - u[i][j]);

    return 1/delta_y * (stencil3 - stencil4) + gamma / delta_y * (stencil5 - stencil6);
}

double dv2_dy(double** u, double** v, int i, int j, double delta_y, double gamma) {
    double stencil1 = 0.5 * (v[i][j] + v[i][j+1]);
    double stencil2 = 0.5 * (v[i][j-1] + v[i][j]);

    double stencil3 = fabs(stencil1) * 0.5 * (v[i][j] - v[i][j+1]);
    double stencil4 = fabs(stencil2) * 0.5 * (v[i][j-1] - v[i][j]);

    return 1/delta_y * (stencil1*stencil1 - stencil2*stencil2) + gamma / delta_y * (stencil3 - stencil4);
}

double duv_dx(double** u, double** v, int i, int j, double delta_x, double gamma) {
    double stencil1 = 0.5 * (u[i][j] + u[i][j+1]);
    double stencil2 = 0.5 * (u[i-1][j] + u[i-1][j+1]);

    double stencil3 = stencil1 * 0.5 * (v[i][j] + v[i+1][j]);
    double stencil4 = stencil2 * 0.5 * (v[i-1][j] + v[i][j]);

    double stencil5 = fabs(stencil1) * 0.5 * (v[i][j] - v[i+1][j]);
    double stencil6 = fabs(stencil2) * 0.5 * (v[i-1][j] - v[i][j]);

    return 1/delta_x * (stencil3 - stencil4) + gamma / delta_x * (stencil5 - stencil6);
}

/**
 * @brief Central differences for second derivatives.
 */

double d2u_dx2(double** u, int i, int j, double delta_x) {
    return (u[i+1][j] - 2 * u[i][j] + u[i-1][j]) / (delta_x*delta_x);
}

double d2u_dy2(double** u, int i, int j, double delta_y) {
    return (u[i][j+1] - 2 * u[i][j] + u[i][j-1]) / (delta_y*delta_y);
}

double d2v_dx2(double** v, int i, int j, double delta_x) {
    return (v[i+1][j] - 2 * v[i][j] + v[i-1][j]) / (delta_x*delta_x);
}

double d2v_dy2(double** v, int i, int j, double delta_y) {
    return (v[i][j+1] - 2 * v[i][j] + v[i][j-1]) / (delta_y*delta_y);
}

double FG(double** F, double** G, double** u, double** v, int i_max, int j_max, double Re, double g_x, double g_y, double delta_t, double delta_x, double delta_y, double gamma) {
    int i, j;
    for (i = 1; i <= i_max; i++) {
        for(j = 1; j <= j_max; j++) {
            if (i <= i_max - 1) {
                F[i][j] = u[i][j] +
                            delta_t * (1/Re * (d2u_dx2(u, i, j, delta_x) +
                            d2u_dy2(u, i, j, delta_y)) -
                            du2_dx(u, v, i, j, delta_x, gamma) -
                            duv_dy(u, v, i, j, delta_y, gamma) +
                            g_x);
            }

            if (j <= j_max - 1) {
                G[i][j] = v[i][j] +
                            delta_t * (1/Re * (d2v_dx2(v, i, j, delta_x) +
                            d2v_dy2(v, i, j, delta_y)) -
                            duv_dx(u, v, i, j, delta_x, gamma) -
                            dv2_dy(u, v, i, j, delta_y, gamma) +
                            g_y);
            }

            // This part quickly segfaults since there are no values for u_imax+1 and v_jmax+1.
        }
    }
}

/**
 * @brief Forward difference stencil for dp/dx.
 */
double dp_dx(double** p, int i, int j, double delta_x) {
    return (p[i+1][j] - p[i][j]) / delta_x;
}

/**
 * @brief Forward difference stencil for dp/dy.
 */
double dp_dy(double** p, int i, int j, double delta_y) {
    return (p[i][j+1] - p[i][j]) / delta_y;
}

/**
 * Returns the L2 norm of a grid with one ghost row/column on each side.
 */
double L2(double** m, int i_max, int j_max) {
    double norm = 0.0;
    int i, j;
    for (i = 1; i <= i_max; i++) {
        for(j = 1; j <= j_max; j++) {
            norm += m[i][j] * m[i][j];
        }
    }
    return sqrt(norm / i_max / j_max);
}

/**
 * @brief SOR.
 */
int SOR(double** p, int i_max, int j_max, double delta_x, double delta_y, double** res, double** RHS, double omega, double eps) {
    int i, j;
    double dydy = delta_y * delta_y;
    double dxdx = delta_x * delta_x;

    int it_max = 500;
    int it = 0;

    double norm_p = L2(p, i_max, j_max);    // L2 norm of grid.
    while (1) {
        // Fill ghost cells with values of neighbourng cells for new iteration step.
        for (j = 1; j <= j_max; j++)
        {
            p[0][j] = p[1][j];
            p[i_max+1][j] = p[i_max][j];
        }
        for (i = 1; i <= i_max; i++) {
            p[i][0] = p[i][1];
            p[i][j_max+1] = p[i][j_max];
        }

        
        // Iterate through grid a calculate new values.
        for (i = 1; i <= i_max; i++) {
            for (j = 1; j <= j_max; j++) {
                p[i][j] = (1.0 - omega) * p[i][j] + omega / (2.0 * (1.0 / dxdx + 1.0 / dydy))
                            * ((p[i+1][j] + p[i-1][j]) / dxdx + (p[i][j+1] + p[i][j-1]) / dydy - RHS[i][j]);
            }
        }

        for (i = 1; i <= i_max; i++) {
            for (j = 1; j <= j_max; j++) {
                res[i][j] = (p[i+1][j] - 2.0*p[i][j] + p[i-1][j]) / dxdx + (p[i][j+1] - 2.0*p[i][j] + p[i][j-1]) / dydy - RHS[i][j];
            }
        }

        //printf("%.5f\n", L2(res, i_max, j_max));
        // Abortion condition.
        if (L2(res, i_max, j_max) <= eps * norm_p + 0.00001) {
            return 0;
        }

        it++;
        if (it > it_max) return 0;
    }

    // This should never be reached.
    return -1;
}
