#include <stdio.h>
#include "pratica4.h"

void main (){
	float a;
	char s;
	printf ("Altura:");
	scanf ("%f", &a);
	printf ("Sexo:");
	scanf (" %c", &s); //colocar um espaço antes de % slá pq.
	float pi = pesoIdeal (a, s);
	printf ("Peso ideal: %f", pi);
}