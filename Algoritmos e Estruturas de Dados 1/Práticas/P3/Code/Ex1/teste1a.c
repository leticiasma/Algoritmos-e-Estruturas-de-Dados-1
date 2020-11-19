#include <stdio.h>
#include "ex1.h"

void main ()
{	float x = 3.14;
	float y = p_int (x);
	printf ("%.2f", y);	//como sei que o valor está vindo da função e não do próprio void main? --> //float y = p_int (x); ao invés de int y
	
	x = -356.876345;
	y = p_int (x);
	printf ("\n%.2f", y);
	
	x = 0.1234567890;
	y = p_int (x);
	printf ("\n%.2f", y);
	
	}