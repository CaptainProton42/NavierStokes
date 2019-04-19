#include "io.h"
#include "memory.h"
#include "integration.h"


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int init(int* i_max, int* j_max, double* a, double* b, double* Re, double* T, double* delta_x, double* delta_y)
{	

	int n = 20; // Maximal number of input parameters
	FILE *f;
	f = fopen("parameters.txt", "r");

	double* parameters = (double*) calloc(n, sizeof(double));


   if (f == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   int i;
   for (i = 0; i < n; i++)
   {
   	fscanf(f, "%lf,",&parameters[i]);
   }

   fclose(f);

   *i_max = parameters[0];
   *j_max = parameters[1];
   *a = parameters[2];
   *b = parameters[3];
   *Re = parameters[4];
   *T = parameters[5];

   *delta_x = *a / *i_max;
   *delta_y = *b / *j_max;

   return 0;
}

int output(int i_max, int j_max, double** u, double** v, double** p, const char* prefix)
{
	int i, j;

    char fname_u[64];
    char fname_v[64];
    char fname_p[64];

    strcpy(fname_u, prefix);
    strcpy(fname_v, prefix);
    strcpy(fname_p, prefix);

    strcat(fname_u, "_u.txt");
    strcat(fname_v, "_v.txt");
    strcat(fname_p, "_p.txt");

    FILE* fp_u,* fp_v, * fp_p;
    fp_u = fopen(fname_u, "w");
    fp_v = fopen(fname_v, "w");
    fp_p = fopen(fname_p, "w");


    // Rows first, then columns
    for (j = 0; j < j_max + 2; j++) {
        for (i = 0; i < i_max + 2; i++) {
            if (i < i_max + 1) fprintf(fp_u, "%.5f ", u[i][j]); // 5 decimal places
            if (j < j_max + 1) fprintf(fp_v, "%.5f ", v[i][j]);
            fprintf(fp_p, "%.5f ", p[i][j]);
        }
        fprintf(fp_u, "\n"); 
        fprintf(fp_v, "\n");
        fprintf(fp_p, "\n");
    }

    fclose(fp_u);
    fclose(fp_v);
    fclose(fp_p);

    printf("Output created!\n");	
    return 0;
}


double smallest_number(int i_max, double* u)
{
   	double min = u[0];
   	int i;

   	for (i = 0; i <= i_max; i++)
   	{
           	if (min > u[i])
           	{
               	min = u[i];
           	}
    	 
    }
    
	return min;
}

double biggest_number(int i_max, int j_max, double** u)
{
   	double max = u[0][0];
   	int i,j;

   	for (i = 1; i <= i_max; i++)
   	{
       	for (j = 1; j <= j_max; j++)
       	{
           	if (max < u[i][j])
           	{
               	max = u[i][j];
           	}
    	} 
    }

	return max;
}

