#include <math.h>
#include "pratica4.h"

//Ex.1
float paraMetrosPorSegundo (float v){
	float m = v/3.6;
	return m;
}

//Ex.2
float areaCirculo (float raio){
	float a = M_PI*pow(raio, 2);
	return a;
}

//Ex.3
int ehPar (int n){
	if (n%2 == 0){
		return 1;
	}
	else {
		return 0;
	}
}

//Ex.4
int ehDivisivelPor3ou5 (int n){ //Não pode usar o operador ^! Ele é bit-a-bit! Para expressões não tem.
	if ((n%3 == 0 || n%5 == 0) && !(n%3 == 0 && n%5 == 0)){
		return 1;
	}
	else {
		return 0;
	}
}

//Ex.5
float pesoIdeal (float h, char sexo){
	if (sexo == 'F'){
	return 62.1*h - 44.7;
	}
	else{
		return 72.7*h - 58;
	}
}

//Ex.6 é programa

//Ex.7
int somaImpares(int N){ //não deu
	int nimpares = 1;
	int somadeles = 0;
	while (nimpares <= N){
		somadeles += nimpares;
		nimpares += 2;
	}
	return somadeles;
}

//Ex.8
	double fatorial (int N){
	double fat = 1;
	int aux = 1;
	while (aux <= N){
		fat *= aux;
	aux++;
	}
	return fat;
}


//Ex.9
int somaNumerosDiv3ou5(int N){
	int soma = 0;
	int num = 1;
	while (num <= N){
		if ((num%3 == 0 || num%5 == 0) && !(num%3 == 0 && num%5 == 0)){
			soma += num; 
		}
	num++;
	}
	return soma;
}

//Ex.10
float calculaMedia (int x, int y, int z, int operacao){
	if (x>0 && y>0 && z>0){
		float op1 = pow (x*y*z, 1/3);
		float op2 = (x + 2*y + 3*z) /6;
		float op3 = 3/ (1/x + 1/y + 1/z);
		float op4 = (x+y+z) /3;
		if  (operacao == 1){
			return op1;
		}
		if  (operacao == 2){
			return op2;
		}
		if  (operacao == 3){
			return op3;
		}
		if  (operacao == 4){
			return op4;
		}
	}
}

//Ex.11	
int numeroDivisores (int N){
	int i = 0;
	int div = 1;
	while (div<=N){
		if(N%div == 0){
		i++;
		}
	div++;
	}
	return i;
}

//Ex.12
int enesimoFibonacci (int N){ //N=3
	int n_menos_2 = 0; //n-2 = 1 , 1
	int n_menos_1 = 1; //n-1 = 1 , 2
	int n = 0; //n = 1 , 2
	int aux = 0; //aux = 1 , 2
	while (aux<N-1){
		n = n_menos_2 + n_menos_1;//n = 
		n_menos_2 = n_menos_1; //n-2 = 
		n_menos_1 = n; //n-1 = 
		aux++; //aux = 
	}
	return n;
}
	
	
//Ex.13
int mdc (unsigned int x, unsigned int y) {
	int div = 1;
	int mdc;
	int menor;
	if (x<y){
		menor = x;
	}
	else {
		menor = y;
	}
	while (div <= menor){
		if (x%div == 0 && y%div == 0){
			mdc = div;
		}
		div++;	
	}
	return mdc;
}

//Ex.14
int mmc(unsigned int x, unsigned int y){
	int mmc;
	if (x>y){
		mmc = x;
	}
	else {
		mmc = y;
	}
	while (mmc%x != 0 || mmc%y !=0){
		mmc++;
	}
	return mmc;
}

//Ex.15 é programa
	