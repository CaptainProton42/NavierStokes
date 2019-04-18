#include "integration.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double u1(double x) {
    return sin(x);
}

int main() {
    int i, j;
    int i_max = 100;
    int j_max = 100;

    double** u = (double**) calloc(i_max, sizeof(double*)); /* u values on the right edges of the ghost cells are not needed */
    double** v = (double**) calloc(i_max, sizeof(double*));
    double** du2_dx_res = (double**) calloc(i_max, sizeof(double*));
    double** dv2_dy_res = (double**) calloc(i_max, sizeof(double*));
    double** duv_dx_res = (double**) calloc(i_max, sizeof(double*));
    double** duv_dy_res = (double**) calloc(i_max, sizeof(double*));

    for (i = 0; i < i_max; i++)
    {
        u[i] = (double*) calloc(j_max, sizeof(double));
        v[i] = (double*) calloc(j_max, sizeof(double)); /* v values on the top edges of the ghost cells are not needed */
        du2_dx_res[i] = (double*) calloc(j_max, sizeof(double));
        dv2_dy_res[i] = (double*) calloc(j_max, sizeof(double));
        duv_dx_res[i] = (double*) calloc(j_max, sizeof(double));
        duv_dy_res[i] = (double*) calloc(j_max, sizeof(double));
    }

    double dx = 0.1;
    double dy = 0.1;
    for (i = 0; i < i_max; i++) {
        for (j = 0; j < j_max; j++) {
            u[i][j] = sin(dx * i);
            v[i][j] = cos(dy * j);
        }
    }

    for (i = 1; i < i_max - 1; i++) {
        for (j = 1; j < j_max - 1; j++) {
            du2_dx_res[i][j] = du2_dx(u, v, i, j, dx, 1.0);
            dv2_dy_res[i][j] = dv2_dy(u, v, i, j, dy, 1.0);
            duv_dx_res[i][j] = duv_dx(u, v, i, j, dx, 1.0);
            duv_dy_res[i][j] = duv_dy(u, v, i, j, dy, 1.0);
        }
    }

    FILE* fp,* fp2,* fp3,* fp4;
    fp = fopen("der.txt", "w");
    fp2 = fopen("der2.txt", "w");
    fp3 = fopen("der3.txt", "w");
    fp4 = fopen("der4.txt", "w");


    // Rows first, then columns
    for (j = 0; j < j_max; j++) {
        for (i = 0; i < i_max; i++) {
            fprintf(fp, "%.5f ", du2_dx_res[i][j]);
            fprintf(fp2, "%.5f ", dv2_dy_res[i][j]);
            fprintf(fp3, "%.5f ", duv_dx_res[i][j]);
            fprintf(fp4, "%.5f ", duv_dy_res[i][j]);
        }
        fprintf(fp, "\n");
        fprintf(fp2, "\n");
        fprintf(fp3, "\n");
        fprintf(fp4, "\n");
    }

    fclose(fp);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
}