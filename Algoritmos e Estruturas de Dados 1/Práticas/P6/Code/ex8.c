#include <stdio.h>

void main(){
	char nome [100];
	char maiusc [100];
	scanf ("%s", nome);
	int i = 0, j = 0;
	while (nome [i] != '.'){
		if (nome [i] >= 65 && nome [i] <= 90){
			maiusc [j] = nome [i];
			j++;
			maiusc [j] = '.';
			j++;
		}
		i++;
	}
	maiusc [j] = '\0'; //Se não colocar esse \0 imprime umas coisas aleatórias, não sei porque.
	printf ("%s", maiusc);
}

