#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "integration.c"
#include "memory.h"

int main() {
    int j_max = 50;
    int i_max = 50;

    double x_size = 10;
    double y_size = 10;
    double** u;
    double** v;
    double** p;

    double dx = x_size / i_max;
    double dy = y_size / j_max;


    allocate_memory(&u, &v, &p, j_max, i_max);
    int i, j;

    
    
    // Assign function values for u = cos(x)cos(y), v=sin(x)sin(y).
    for (i = 0; i < i_max; i++) {
        for (j = 0; j < j_max; j++) {
            //u[i][j] = cos(i*dx + 0.5*dx) * cos(j*dy);
            //v[i][j] = sin(i*dx ) * sin(j*dy + 0.5*dy);
            u[i][j] = 1;
            v[i][j] = 1;
        }
    }
    
    
    // Print lattice to file.
    FILE* fp_u,* fp_v;
    fp_u = fopen("u.txt", "w");
    fp_v = fopen("v.txt", "w");

    // Lines first, then columns
    for (j = 0; j < j_max; j++) {
        for (i = 0; i < i_max; i++) {
            fprintf(fp_u, "%.5f ", u[i][j]);
            fprintf(fp_v, "%.5f ", v[i][j]);
        }
        fprintf(fp_u, "\n"); 
        fprintf(fp_v, "\n");
    }

    fclose(fp_u);
    fclose(fp_v);

    return 0;
}