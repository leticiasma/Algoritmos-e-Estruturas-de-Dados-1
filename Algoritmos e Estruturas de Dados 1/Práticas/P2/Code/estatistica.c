#include <stdio.h>
#include <math.h>
#include "estatistica.h"

float cauchy (float x)
{
float c;	
c=1/(M_PI*(1+pow(x,2)));

return c;
}

float gumbel (float x, float u, float b)
{
float g;	
float z;
z=(x-u)/b;
g= (1/b)*exp(-(z+exp(-z)));

return g;
}

float laplace(float x, float u, float b)
{
float l;	
float f;
f=(-fabs(x-u))/b;
l=(1/(2*b))*exp(f);

return l;	
}