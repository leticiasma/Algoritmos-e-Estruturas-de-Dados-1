#include "ex3func.h"
//int tamanhovet (float vetor []){
//	int i;
//	for (i=0; i)
	
//}

float mediavet (float vetor [], int n){
	int i;
	float media, soma = 0;
	for (i=0;i<n;i++){
		soma += vetor[i]; 
	}
	media = soma/2;
	return media;

}