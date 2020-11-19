#include <stdio.h>
#include <stdlib.h>

void main (){
	char linha[128]; 
	printf("digite uma linha:\n"); 
	fgets(linha, 128, stdin);                     //oq é esse stdin?
	                                              //printf ("%s", linha);
	int cont = 0, i = 0;
	while (linha [i] != '\n'){ //esa função não usa o \0?
			i++; 
			cont++;
	}
	printf ("Tem %d caracteres", cont);
}
                                                   