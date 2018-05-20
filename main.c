#include <stdio.h>
#include <math.h>
#include "fixedpoint.h"

#define SAMPLES 20000

FILE *fpin;
FILE *fpout;
FILE *fpcoef;

void main(int argc, char* argv[])
{
  printf("%s",argv[1]);
  fpin = fopen(argv[1],"r");
  fpcoef = fopen("coef.txt","r");
  fpout = fopen("filtered.csv","w");

  //Load Filter Parameters
  int A_In=0;
  int a1=0;
  int a2=0;
  int b0=0;
  int b1=0;
  int i=0;
  float ph;
  fscanf(fpcoef,"%d",&A_In);
  fscanf(fpcoef,"%f",&ph);
  a1=ShiftInt(ph);
  fscanf(fpcoef,"%f",&ph);
  a2=ShiftInt(ph);
  fscanf(fpcoef,"%f",&ph);
  b0=ShiftInt(ph);
  fscanf(fpcoef,"%f",&ph);
  b1=ShiftInt(ph);

  //Set Tap States to 0
  int y=0;
  int y1=0;
  int y2=0;
  int x=0;
  int x1=0;
  float x_in=0.0;
  
  for(i=0;i<SAMPLES;i++)
  {
    fscanf(fpin, "%f", &x_in);
    if(x_in == -1) x_in = 0.0;  //If the file ends give zeroes
    x=ShiftInt(x_in);
    y=ShiftedMult(x,b0)+ShiftedMult(x1,b1)-ShiftedMult(y1,a1)-ShiftedMult(y2,a2);

    //Update Taps
    y2=y1;
    y1=y;
    x1=x;
    fprintf(fpout,"%f\n",ShiftFloat(y));
  }
  fclose(fpin);
  fclose(fpout);
  fclose(fpcoef);
  printf("\n%s filtered to %d points.\n\n", argv[1], SAMPLES);
  printf("Filter parameters in decimal notation:");
  printf("\na1 = %1.4f a2 = %1.4f \nb0 = %1.4f b1 = %1.4f A_In = %1.4f\n",
         ShiftFloat(a1),ShiftFloat(a2),ShiftFloat(b0),ShiftFloat(b1),ShiftFloat(A_In));


}