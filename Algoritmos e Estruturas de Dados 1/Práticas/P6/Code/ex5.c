#include <stdio.h>

void main(){
	char texto [10000];
	scanf ("%s", texto);
	int i;
	for (i = 0; texto [i] != '\0' ; i++){ //For é como aquilo de "k variando de zero a n" e vai percorrendo as coisas
		texto [i] -= 32;
	} 
	printf ("%s", texto);
}