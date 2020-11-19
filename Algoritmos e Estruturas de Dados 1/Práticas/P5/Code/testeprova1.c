#include <stdio.h>
#include "prova1.h"

void main (){
	int x = 10;
	int y = 20;
	int a = primosEntreSi (x, y);
	printf ("%d", a);
	x = 3;
	y = 5;
	a = primosEntreSi (x,y);
	printf ("\n%d", a);
	
	x = 9;
	y = 15;
	a = phi(x);
	printf ("\n\n%d", a);
	a = phi (y);
	printf ("\n%d", a);
	
	int *b = &x;
	int *c = &y;
	maiorPhi (b, c);
	printf ("\n\n%d \n%d", *b, *c);
}