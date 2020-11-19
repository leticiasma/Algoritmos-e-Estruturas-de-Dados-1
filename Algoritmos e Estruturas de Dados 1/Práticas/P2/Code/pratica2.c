#include <stdio.h>
#include <math.h>
#include "estatistica.h"

 
 void main ()
 {
float x;
float u;
float b;
float y;

x=-2;
y=cauchy (x);
printf ("Cauchy = %f", y);

x=0;
u=0.5;
b=2;
y=gumbel (x,u,b);
printf ("\nGumbel = %f%", y);

x=-6;
u=-5;
b=4;
y=laplace (x,u,b);
printf("\nLaplace = %f", y); 

 }
 
 