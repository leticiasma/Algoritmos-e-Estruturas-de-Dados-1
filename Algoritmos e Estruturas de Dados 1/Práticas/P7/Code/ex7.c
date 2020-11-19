#include <stdio.h>
#include <stdlib.h>

void main(){
	int i,aux, maior, menor, nummenor, nummaior;
	int vetcont [1000];
	for (i=0;i<1000;i++){
		vetcont [i]=0;
	}
	for (i=0;i<=5000000;i++){
		aux = rand()%1000;
		vetcont [aux]++;
	}
	maior = vetcont [0];
	menor = vetcont [0];
	for (i=0;i<1000;i++){
		if (vetcont [i]>maior){
			maior = vetcont [i];
			nummaior = i;
		}
	}
	for (i=0;i<1000;i++){
		if (vetcont [i]<menor){
			menor = vetcont [i];
			nummenor = i;
		}
	}
	for (i=0;i<1000;i++){
		printf ("%d: %d ", i, vetcont [i]);
	}
	int diferenca = maior - menor;
	printf ("\nO que mais foi contado foi %d, o que menos foi contado foi o %d e a diferenca na contagem eh: %d ", nummaior, nummenor, diferenca);
}