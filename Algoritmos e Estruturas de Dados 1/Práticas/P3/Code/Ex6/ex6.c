#include "ex6.h"

int ddd (unsigned int number){
	int x = number/1000000;
	return x;
}

int soma1SePar(unsigned int number){
	int x = number | 1;
	return x;
}

int parOuImpar(unsigned int number){
	int x = number;
	int y = soma1SePar (number);
	return y - x;
}