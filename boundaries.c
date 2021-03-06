#include "boundaries.h"

int set_noslip(int i_max, int j_max, double** u, double** v, int side) {
    return set_inflow(i_max, j_max, u, v, side, 0, 0);
}

int set_inflow(int i_max, int j_max, double** u, double** v, int side, double u_fix, double v_fix) {
    int i,j;
    switch(side) {
        case TOP:            
            for (i = 1; i <= i_max; i++) {
                v[i][j_max] = v_fix; /* Set fixed values on border. */
                u[i][j_max + 1] = 2 * u_fix - u[i][j_max]; /* Set values with no exact border value by averaging. */
            }
            break;
        case BOTTOM:           
            for (i = 1; i <= i_max; i++) {
                v[i][0] = v_fix;
                u[i][0] = 2 * u_fix - u[i][1];
            }
            break;
        case LEFT:        
            for (j = 1; j <= j_max; j++) {
                u[0][j] = u_fix;
                v[0][j] = 2 * v_fix  - v[1][j];
            }
            break;
        case RIGHT:            
            for (j = 1; j <= j_max; j++) {
                u[i_max][j] = u_fix;
                v[i_max+1][j] = 2 * v_fix - v[i_max][j];
            }
            break;
        default: 
            return -1;
    }

    return 0;
}