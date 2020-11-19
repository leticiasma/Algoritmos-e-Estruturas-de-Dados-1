#include <stdio.h>
#include <stdlib.h>
#include "ex3func.h"

void main(){
	float v [5];
	int i;
	for (i=0; i<5;i++){
		v[i]=1 + ((float)rand()/RAND_MAX)*9;
		printf ("%f ", v[i]);
	}
	printf ("\n");
	int n = 5;
	float media;
	media = mediavet (v, n);
	printf ("A media eh: %f", media);
}