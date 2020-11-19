#include <stdio.h>

//tentar para um scanf, com aninhamento de if e sem montar um vetor novo (cuidado com o \0) 
void main(){
	char texto [6] = "arara"; //já tem o '\0', ou seja, esse vetor é o {'a','r','a','r','a','\0'}
	char texto2 [6]; //dar um jeito de colocar o '\0'
	int i = 0, j = 4;
	while (i<=4 && j>= 0){
		texto2 [j] = texto [i];
		i++;
		j--;
	}
	texto2 [5] = '\0'; //olha ele aí!
	//printf ("%s %s\n", texto, texto2);
										//texto2 [0] = 'i'; teste para comprovar que eu montei mesmo o 2 vetor corretamente
	//texto2 [0] = 'i'; //teste para ver se a comparação esta funcionando
	//printf ("%s %s\n", texto, texto2);
	i = 0;
	j = 0;
	int aux = 0;
	while (i <= 4 && j <= 4){
		if (texto [i] == texto2 [j]){
			aux += 1 ;
		}
		else{
			aux += 0;
		}
		i++;
		j++;
	}
	if (aux == 5){
		printf ("Eh palindromo");
	}
	else {
		printf ("Nao eh palindromo");
	}
	
}