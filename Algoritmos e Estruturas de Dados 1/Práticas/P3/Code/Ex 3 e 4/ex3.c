#include <stdio.h>
#include "ex4.h"

void main () 
{	float x, y; 
	scanf ("%f %f", &x, &y);
	float *px = &x; // testar a diferença de todas essas coisas confusas printf ("O endereco de x e: %p e o conteudo de px e: %d", &x, px );
	float aux = x;
	float *py = &y;
	*px = y;
	*py = aux;
	printf("\nx = %f\ny = %f\n", x, y); 
	
	float a, b;
	scanf ("%f %f", &a, &b);
	float *pa = &a;
	float *pb = &b;
	troca(pa, pb);
	printf("\na = %f\nb = %f", a, b);
	
} 
 