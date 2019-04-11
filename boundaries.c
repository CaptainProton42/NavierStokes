#include "boundaries.h"

int set_noslip(double** u, double** v, int side) {
    return set_inflow(u, v, side, 0, 0);
}

int set_inflow(double** u, double** v, int side, double u_fix, double v_fix) {
    switch(side) {
        case TOP:
            int i;
            for (i = 0; i < i_max+2; i++) {
                v[i][j_max] = v_fix; /* Set fixed values on border. */
                u[i][i_max + 1] = 2 * u_fix - u[i][j_max]; /* Set values with no exact border value by averaging. */
            }
            break;
        case BOTTOM:
            int i;
            for (i = 0; i < i_max+2; i++) {
                v[i][0] = v_fix;
                u[i][0] = 2 * u_fix - u[i][1];
            }
            break;
        case LEFT:
            int j;
            for (j = 0; j < j_max+2; j++) {
                u[0][j] = u_fix;
                v[0][j] = 2 * v_fix  - v[1][j];
            }
            break;
        case RIGHT:
            int j;
            for (j = 0; j < j_max+2; j++) {
                u[i_max][j] = u_fix;
                v[i_max+1][j] = 2 * v_fix - v[i_max][j];
            }
            break;
        default: 
            return -1;
    }

    return 0;
}