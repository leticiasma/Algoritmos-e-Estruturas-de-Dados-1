#include "prova1.h"
#include <stdio.h>

void main (){
	int a, b;
	printf ("\ndigite dois valores positivos: ");
	do{
		scanf("%d %d", &a, &b);
	} while (a<=0 || b<=0);
	maiorPhi(&a,&b);
	printf("\no numero %d tem o maior phi: %d", a, b);
}