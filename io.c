#include "io.h"
#include "globals.h"

#include <stdlib.h>
#include <stdio.h>

double init_grid()
{	

	int n = 20; // Maximal number of input parameters
	FILE *f
	f = fopen("parameters.txt", "r")

	double parameters[n];
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
   j_max = paramteres[1];
   a = parameters[2];
   b = parametes[3];
   Re = parameters[4];
   T = parameters[5];

   delx = a/i_max:
   dely = b/j_max;
   parameters[6] = delx;
   parameters[7] = dely;

   cells_number = (i_max + 1) * (j_max + 1);
   parameters[8] = cells_number;

   return parameters;
}
