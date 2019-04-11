#include "io.h"
#include "globals.h"

#include <stdlib.h>
#include <stdio.h>

double init_grid()
{	

	char ch;

	FILE *f = fopen("parameters.dat", "r")

   if (f == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   char *buf[100];
   while (fscanf(f,"%*s %*s %s ",buf)==1)
   	printf("%s\n", buf);

   fclose(f);
   return 0;
}
