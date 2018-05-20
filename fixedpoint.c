#include <stdio.h>
#include <math.h>
#include "fixedpoint.h"

float ShiftFloat(int Ival)
{
  int Scaledown=1<<BITSHIFT;
  float Smallval = 0.0;
  Smallval = ((float)Ival) / ((float)Scaledown);
  return Smallval;
}

int ShiftInt(float Ival)
{
  int Scaleup=1<<BITSHIFT;
  float Bigval = (float)Scaleup * Ival;
  return (int)Bigval;
}

int ShiftedMult(int A, int B)
{
  return (A*B)>>(BITSHIFT);
}
