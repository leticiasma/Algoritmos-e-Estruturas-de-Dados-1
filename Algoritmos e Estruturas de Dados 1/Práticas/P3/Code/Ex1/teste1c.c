#include <stdio.h>
#include "ex1.h"

void main ()
{	int x = 6;
	int y = 3;
	float div = div_ints (x, y);
	printf ("%f", div);
	
	x = 3;
	y = 6;
	div = div_ints (x, y);
	printf ("\n%f", div);
	
	x = 32;
	y = 9;
	div = div_ints (x, y);
	printf ("\n%f", div);
}
