#include "integration.h"
#include "memory.h"
#include "io.h"

int main() {
    int i, j;
    int i_max = 200;
    int j_max = 200;

	double** u;
	double** v;
	double** p;

    double** F;
    double** G;
    double** res;
    double** RHS;

    allocate_memory(&u, &v, &p, &res, &RHS, &F, &G, i_max, j_max);

    // Set boundary conditions.
    for (i = 1; i <= i_max; i++) {
        p[i][1] = 1.0;
        p[i][j_max] = 1.0;
    }

    for (j = 1; j <= j_max; j++) {
        p[1][j] = 1.0;
        p[i_max][j] = 1.0;
    }

    for (i=1; i<=i_max; i++) {
        for (j=1; j<=j_max; j++) {
            RHS[i][j] = 0.0;//-2.0 *p[i][j];
        }
    }
    SOR(p, i_max, j_max, 0.01, 0.01, res, RHS, 1.7, 0.001, 5000);

    output(i_max, j_max, u, v, p, "poisson");
}