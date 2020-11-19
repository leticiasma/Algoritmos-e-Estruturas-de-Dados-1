#include <stdio.h>
#include "ex6.h"

void main (){
	int x = 12988181;
	int y = ddd (x);
	printf("%d", y);
	x = 32988181;
	y = ddd (x);
	printf("\n%d", y);
	x = 31982289;
	y = ddd (x);
	printf("\n%d", y);

	int a = 5;
	int b = 32;
	int c = 99;
	x = soma1SePar (a);
	y = soma1SePar (b);
	int z = soma1SePar (c);
	printf("\n%d \n%d \n%d", x, y, z);
	
	a = 2;
	b = 1;
	c = 55;
	x = parOuImpar (a);
	y = parOuImpar (b);
	z = parOuImpar (c);
	printf ("\n%d \n%d \n%d", x, y, z);
}