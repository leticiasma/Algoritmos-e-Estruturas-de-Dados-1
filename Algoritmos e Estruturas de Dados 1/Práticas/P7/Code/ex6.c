#include <stdio.h>
#include <stdlib.h>

void main(){
	int X [60];
	int Y [60];
	int i;
	int vetcont [366];
	for (i=0;i<366;i++){
		vetcont [i] = 0;
	}
	for (i=0;i<60;i++){
		X [i] = rand()%366;
		vetcont [X[i]]++;
	}
	for (i=0;i<60;i++){
		Y [i] = rand()%366;
		vetcont [Y[i]]++;
	}
	printf ("O vetor X eh: ");
	for (i=0;i<60;i++){
		printf ("%d ", X [i]);
	}
	printf ("\nO vetor Y eh: ");
	for (i=0;i<60;i++){
		printf ("%d ", Y [i]);
	}
	printf ("\nO vetor uniao eh:");
	for (i=0;i<366;i++){
		if (vetcont [i] != 0){
			printf ("%d ", i);
		}
	}
}