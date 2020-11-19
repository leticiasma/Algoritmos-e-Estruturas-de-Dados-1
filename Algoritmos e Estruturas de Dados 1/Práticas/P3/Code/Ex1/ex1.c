#include <stdio.h>
#include "ex1.h"

//Ex a
float p_int (float x)
{	//float f = x;
	return (int) x;	
}

float p_frac (float x)
{	//dá, mas fica estranho float f = x - (int)x;
	return f;
	
	//travei
}

float div_ints (int x, int y)
{	float f = (float)x/y;
	return f;	
}