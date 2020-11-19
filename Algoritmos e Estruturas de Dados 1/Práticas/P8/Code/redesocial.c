//Não deu tempo de terminar antes do prazo, mas farei depois para treinar para a prova

#include <stdio.h>
#include <stdlib.h>
#include "redesocial.h"

int M[NUM_PESSOAS][NUM_PESSOAS];

void inicializar_rede(){
	int i, j;
	for (i=0;i<NUM_PESSOAS;i++){
		for (j=0;j<NUM_PESSOAS; j++){
			M[i][j]=0;
		}
	}
}

void adicionar_amizade(int i, int j){
	M [i][j] = 1;
	M [j][i] = 1;
}

float random_float(){
	float aux = rand()/RAND_MAX;
	return aux;
}

void popularRedeSocialAleatoriamente(float P){
	int i,j;
	float aux;
	for (i=0;i<NUM_PESSOAS;i++){
		for (j=0;j<NUM_PESSOAS;j++){
			aux = random_float();
			if (i!=j && aux<P){ //if (i!=j && M[i][j] !=1 && aux<P){
				adicionar_amizade;
			}
		}
	}
}

void imprimirRedeSocial(){
	int i,j;
	for (i=0; i<NUM_PESSOAS;i++){
		for (j=0; j<NUM_PESSOAS; j++){
			printf ("%d ", M[i][j]);
		}
		printf ("\n");
	}
}

int numAmigosEmComum(int v, int u){
	
}



