#include <stdio.h>

void ordVet (int vet[], int n){
	int aux = 0, aux2 = 0;
	int i, j, k = 0;
	for (i=0; i<n; i++){
		aux = vet[i];
		k=i;
		for (j=i; j<n; j++){
			if (vet[j]<aux){
				aux = vet[j];
				k = j;
			}
		}
		aux2 = vet[i];
		vet[i] = aux;
		vet[k] = aux2;
	}
	
}

void main(){
	/*Pq dá bug quanto tem 0 no vetor?
	int i, n = 6;
	int veteste [6] = {4,1,2,10,3,5};
	for (i=0; i<6; i++){
		printf ("%d ", veteste[i]);
	}
	printf ("\n");
	ordVet(veteste,n);
	for (i=0; i<6; i++){
		printf ("%d ", veteste[i]);
	}*/
	int i,j=0;
	int jogo[6];
	int numvenc=0, numlost=0;
	FILE *arq; 
	arq = fopen("cartelas.txt", "r"); 
	int vencedor[6] =  {6,9,22,23,48,52};
	int lost[6] = {4,8,15,16,23,42};
	while(feof(arq) == 0) {
		//for (i=0; i<3; i++){
			//for (j=0; j<3; j++){
		fscanf (arq, "%d", &jogo[j]);
		j++;
		if (j==6){
			ordVet (jogo, 6);
			if (jogo[0]==vencedor[0]&&jogo[1]==vencedor[1]&&jogo[2]==vencedor[2]&&jogo[3]==vencedor[3]&&jogo[4]==vencedor[4]&&jogo[5]==vencedor[5]){
				numvenc++;
			}
			if (lost[0]==jogo[0]&&lost[1]==jogo[1]&&lost[2]==jogo[2]&&lost[3]==jogo[3]&&lost[4]==jogo[4]&&lost[5]==jogo[5]){
				numlost++;
			}
			j=0;
		}
	}
	fclose (arq); 
	printf ("%d %d", numvenc, numlost);
}


	
