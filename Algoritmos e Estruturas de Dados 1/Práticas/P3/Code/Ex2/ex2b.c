#include <stdio.h>
#include "ex2c.h"

void main ()
{
	int x = 0;
	int *y = &x;
	*y = *y + 3;
	printf ("%d", x);

		//usando uma função
	x = 0;
	soma1 (y);
	soma1 (y);
	soma1 (y);
	printf ("\n%d", x);
	
	
}

