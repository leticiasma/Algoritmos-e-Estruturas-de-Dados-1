#include <stdio.h>
#include <math.h>
#include "funcaoex1.h"

void main (){
	double e = 1.0;
	int i = 1;
	while ((float)1/fatorial (i) >= pow (10, -6)){
		e += (float)1/fatorial (i);
		i++;
	}
	printf ("%f", e);
}