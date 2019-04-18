#include "integration.h"
#include "io.h"

int main() {
    int i, j;
    int N;
    int dimx = 10;
    int dimy = 10;

	double** u;
	double** v;
	double** p;

    double** F;
    double** G;
    double** res;
    double** RHS;

    int n;
    for (n=0; n < N; n++) {
        for (i=1; i<=dimx; i++) {
            for (j=1; j<=dimy; j++) {
                RHS[i][j] = - 2 * p[i][j];
            }
        }
        SOR(p, dimx, dimy, 0.1, 0.1, res, RHS, 1.5, 0.1);
    }

    output(dimx, dimy, u, v, p);
}