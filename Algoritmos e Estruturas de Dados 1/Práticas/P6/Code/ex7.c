#include <stdio.h>
#include <stdlib.h>

void main (){
	char texto [5]; //usa isso ou vai mandando imprimir caractere por caractere?
	char c;
	int i = 0;
	while (i < 4 && texto [i] != '.'){
		c = getc(stdin); //Pra que serve esse stdin? Como essa função funciona?
		texto [i] = c;
		i++;
	}
	//texto [4] = '\0'; //tem que fazer isso ou ao invés de \0 usa o . ?
	//texto [2] = 'a'; //Teste para ver se o while está funcionando
	i = 3;
	while (i >=0){
		printf ("%c", texto [i]); //assim ou a string toda em %s?
		i--;
	}
}

