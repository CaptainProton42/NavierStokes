 #include "memory.h"

 int allocate_memory(int i_max, int j_max) {
    int i, j;
    p = (double**) calloc(i_max + 2, sizeof(double*));
    u = (double**) calloc(i_max + 1, sizeof(double*)); /* u values on the right edges of the ghost cells are not needed */
    v = (double**) calloc(i_max + 2, sizeof(double*));
    for (i = 0; i < i_max + 2; i++)
    {
        double* p_i = (double*) calloc(j_max + 2, sizeof(double));
        double* u_i = (double*) calloc(j_max + 2, sizeof(double));
        double* v_i = (double*) calloc(j_max + 1, sizeof(double)); /* v values on the top edges of the ghost cells are not needed */
    }
    
    return 0;
}