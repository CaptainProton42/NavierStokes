#include "io.h"
/*#include "globals.h"*/
#include "memory.h"
#include "integration.h"


#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int init(int* i_max, int* j_max, double* a, double* b, double* Re, double* T, double* g_x, double* g_y, double* tau)
{	

	int n = 20; // Maximal number of input parameters
    char buffer[256];
	FILE *f;
	f = fopen("parameters.txt", "r");

   if (f == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

    fgets(buffer, 256, f);
    sscanf(buffer, "%lf", i_max);
    fgets(buffer, 256, f);
    sscanf(buffer, "%lf", j_max);
    fgets(buffer, 256, f);
    sscanf(buffer, "%lf", a);
    fgets(buffer, 256, f);
    sscanf(buffer, "%lf", b);
    fgets(buffer, 256, f);
    sscanf(buffer, "%lf", T);
    fgets(buffer, 256, f);
    sscanf(buffer, "%lf", Re);
    fgets(buffer, 256, f);
    sscanf(buffer, "%lf", g_x);
    fgets(buffer, 256, f);
    sscanf(buffer, "%lf", g_y);
    fgets(buffer, 256, f);
    sscanf(buffer, "%lf", tau);

    fclose(f);

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

