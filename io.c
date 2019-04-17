#include "io.h"
#include "globals.h"
#include "memory.h"
#include "integration.h"


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double* init()
{	

	int n = 20; // Maximal number of input parameters
	FILE *f;
	f = fopen("parameters.txt", "r");

	double* parameters = (double*) calloc(n, sizeof(double));
	int i;



   if (f == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   for (i = 0; i < n; i++)
   {
   	fscanf(f, "%d,",&parameters[i]);
   }

   fclose(f);

   i_max = parameters[0];
   j_max = parameters[1];
   a = parameters[2];
   b = parameters[3];
   Re = parameters[4];
   T = parameters[5];

   delx = a/i_max;
   dely = b/j_max;
   parameters[6] = delx;
   parameters[7] = dely;

   cells_number = (i_max + 1) * (j_max + 1);
   parameters[8] = cells_number;

   return parameters;
}

double output(double** u, double** v)
{
	int i, j;

    FILE* fp_u,* fp_v;
    fp_u = fopen("u.txt", "w");
    fp_v = fopen("v.txt", "w");

    // Rows first, then columns
    for (j = 0; j < j_max; j++) {
        for (i = 0; i < i_max; i++) {
            fprintf(fp_u, "%.5f ", u[i][j]); // 5 decimal places
            fprintf(fp_v, "%.5f ", v[i][j]);
        }
        fprintf(fp_u, "\n"); 
        fprintf(fp_v, "\n");
    }

    fclose(fp_u);
    fclose(fp_v);

    return 0;
}