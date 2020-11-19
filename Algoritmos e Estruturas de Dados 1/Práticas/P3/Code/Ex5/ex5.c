#include <math.h> //Precisava dessa biblioteca pra resolver?
#include <stdio.h>

unsigned long long int fast_pow_2 (int exp)
{
	int y = 2 << exp; //NÃO ESQUECE DE DECLARAR O Y!
	return y;
}

void main (){
unsigned long long int x = 63;
int y = fast_pow_2 (x) - 1;
printf("%llu", y);
//y++;
//printf ("%llu", y);
}