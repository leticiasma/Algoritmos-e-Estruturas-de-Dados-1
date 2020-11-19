#include "prova1.h"

int primosEntreSi (unsigned int x, unsigned int y){
	int i = 0; 
	int div = 1;
	while (x>=div && y >=div){
		if (x%div == 0 && y%div ==0){
			i++;
		}
		div ++;
	}
	if (i==1){
		return 1;
	}
	else {
		return 0;
	}
}


int phi (unsigned int x){
	int i = 0;
	int co_primos = 1;
	while (co_primos <= x){
		if (primosEntreSi (co_primos, x)){
			i++;
		}
		co_primos++;
	}
	return i;
}

void maiorPhi (int *end_var1, int *end_var2){
	int toti1 = phi (*end_var1);
	int toti2 = phi (*end_var2);
	if (toti1 > toti2){
		*end_var2 = toti1;
	}
	else{
		*end_var1 = *end_var2;
		*end_var2 = toti2;
	}
}