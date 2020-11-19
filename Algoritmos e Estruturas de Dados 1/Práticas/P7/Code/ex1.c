#include <stdio.h>

void main(){
	float u [100] = {1.5, 2.0, 3.2};
	float v [100] = {4.0,5.1, 6.0};
	float uxv;
	int du = 3;
	int dv = 3;
	if (du == dv){
		uxv = u[0]*v[0] + u[1]*v[1] + u[2]*v[2];
		printf ("u x v = %f", uxv);
	}
	else{
		printf ("Tamanhos vetorial não compatíveis");
	}
	
}
