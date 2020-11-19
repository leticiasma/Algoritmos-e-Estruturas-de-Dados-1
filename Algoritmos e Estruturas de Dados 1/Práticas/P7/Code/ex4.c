#include <stdio.h>

void main(){
	int X [10];
	int Y [10];
	int Z [20];
	int i, j=0, k=0;
	printf ("10 valores para X:\n");
	for (i=0;i<10;i++){
		scanf ("%d", &X [i]); //Não esquece desse &!
	}
	for (i=0;i<10;i++){
		printf ("%d ", X [i]);
	}
	printf ("\n10 valores para Y:\n");
	for (i=0;i<10;i++){
		scanf ("%d", &Y [i]); //Não esquece desse &!
	}
	for (i=0;i<10;i++){
		printf ("%d ", Y [i]);
	}
	for (i=0;i<20;i++){
		if (i%2 == 0){
			Z [i] = X [j];
			j++;
		}
		else {
			Z [i] = Y [k];
			k++;
		}
	}
	printf ("\n");
	for (i=0;i<20;i++){
		printf ("%d ", Z [i]);
	}
}