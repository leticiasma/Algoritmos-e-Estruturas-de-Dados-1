#include <stdio.h>


void main (){
	int tam;
	int i,j;
	
	printf ("Qual eh o tamanho do vetor? ");
	scanf ("%d", &tam);
	
	int vet [tam];
	printf ("Escreva o vetor:\n");
	for (i=0;i<tam;i++){
		scanf ("%d", &vet [i]); //Olha o bendito &
	}
	
	printf ("Seu vetor eh: ");
	for (i=0;i<tam;i++){
		printf ("%d ", vet [i]);
	}
	
	int vetinv[tam];
	j=0;
	for (i=tam-1;i>=0;i--){
		vetinv [i] = vet [j];
		j++;
	}
	printf ("\nO inverso do vetor eh: ");
	for (i=0;i<tam;i++){
		printf ("%d ", vetinv [i]);
	}
	
	
}