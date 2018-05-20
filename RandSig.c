//RandSig.c

#include <stdio.h>
#include <math.h>

#define SAMPLES 1000
#define BITSHIFT 13

int SignedBitRand(int);
float ShiftFloat(int);

void main()
{
	int ic,x;
	FILE *fp;

	fp=fopen("randsig.csv","w");
	for(ic=0;ic<SAMPLES;ic++)
	{
	  fprintf(fp, "%f\n", ShiftFloat(SignedBitRand(10)));
	}
	fclose(fp);


	printf("Integers have: %d bits in this system.\n",8*sizeof(int));
}

float ShiftFloat(int Ival)
{
  int Scaledown=1<<BITSHIFT;
  float Smallval = 0.0;
  Smallval = ((float)Ival) / ((float)Scaledown);
  return Smallval;
}


int SignedBitRand(int Bits)
{
	int x;
	Bits=Bits+1;
	x = rand()>>(sizeof(int)*8-Bits);
	x = x-(1<<(Bits-2));
	return x;
}
