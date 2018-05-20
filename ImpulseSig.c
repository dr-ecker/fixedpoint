//ImpulseSig.c

#include <stdio.h>
#include <math.h>

#define SAMPLES 1000

void main()
{
	int ic,x;
	FILE *fp;

	fp=fopen("impulsesig.csv","w");
	fprintf(fp, "100\n");
	for(ic=1;ic<SAMPLES;ic++)
	{
		fprintf(fp, "0\n");
	}
	fclose(fp);
	printf("Integers have: %d bits in this system.\n",8*sizeof(int));
}


