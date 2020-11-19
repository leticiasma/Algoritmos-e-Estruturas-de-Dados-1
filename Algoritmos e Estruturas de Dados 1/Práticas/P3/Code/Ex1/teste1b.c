#include <stdio.h>
#include "ex1.h"

void main () {
	float x = 23.547; //curioso --> float x = 23.56;
	float y = p_frac (x);
	printf ("%f", y);
	
	x = 3.14;
	y = p_frac (x);
	printf ("\n%f", y);
	
	x = -0.222;
	y = p_frac (x);
	printf ("\n%f", y);
	
}