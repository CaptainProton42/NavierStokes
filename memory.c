 #include "memory.h"

 int allocate_memory(double*** u, double*** v, double*** p, double*** res, double*** RHS, double*** F, double*** G, int i_max, int j_max) {
    int i, j;
    *p = (double**) calloc(i_max + 2, sizeof(double*));
    *u = (double**) calloc(i_max + 1, sizeof(double*)); /* u values on the right edges of the ghost cells are not needed */
    *v = (double**) calloc(i_max + 2, sizeof(double*));
    *res = (double**) calloc(i_max + 2, sizeof(double*));
    *RHS = (double**) calloc(i_max + 2, sizeof(double*));
    *F = (double**) calloc(i_max + 2, sizeof(double*));
    *G = (double**) calloc(i_max + 2, sizeof(double*));
    for (i = 0; i < i_max + 2; i++)
    {
        (*p)[i] = (double*) calloc(j_max + 2, sizeof(double));
        (*v)[i] = (double*) calloc(j_max + 1, sizeof(double)); /* v values on the top edges of the ghost cells are not needed */
        if (i < i_max+1) {
            (*u)[i] = (double*) calloc(j_max + 2, sizeof(double));
        }
        (*res)[i] = (double*) calloc(j_max + 2, sizeof(double));
        (*RHS)[i] = (double*) calloc(j_max + 2, sizeof(double));
        (*F)[i] = (double*) calloc(j_max + 2, sizeof(double));
        (*G)[i] = (double*) calloc(j_max + 2, sizeof(double));
    }
    
    return 0;
}