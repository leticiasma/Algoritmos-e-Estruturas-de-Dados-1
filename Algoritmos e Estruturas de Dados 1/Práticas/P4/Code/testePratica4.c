#include <stdio.h>
#include <math.h>
#include "pratica4.h"

void main (){

	//Ex.1
	float x = 100.0;
	float y = paraMetrosPorSegundo(x);
	printf("1-Em m/s: %f", y);

	//Ex.2
	x = 2.0;
	y = areaCirculo (x);
	printf("\n2-Area: %f", y);
	
	//Ex.3
	int a = 3;
	int b = 4;
	int fa = ehPar (a);
	int fb = ehPar (b);
	printf ("\n3-a eh: %d e b eh: %d", fa, fb);
	
	//Ex.4
	a = 5;
	b = 15;
	int c = 2;
	fa = ehDivisivelPor3ou5 (a);
	fb = ehDivisivelPor3ou5 (b);
	int fc = ehDivisivelPor3ou5 (c);
	printf ("\n4-Para 5: %d, para 15: %d e para 2: %d", fa, fb, fc);
	
	//Ex.5
	char sf = 'F';
	char sm = 'M';
	float h = 1.7;
	float fhf = pesoIdeal (h, sf);
	float fhm = pesoIdeal (h, sm);
	printf ("\n5-O pi DELA eh: %f e o DELE eh: %f", fhf, fhm);
	
	//Ex.6 é programa
	
	//Ex.7
	a = 1;
	b = 5;
	c = 10;
	fa = somaImpares (a);
	fb = somaImpares (b);
	fc = somaImpares (c);
	printf ("\n7-%d %d %d", fa, fb, fc);
	
	//Ex.8
	a = 5;
	b = 3;
	c = 1;
	double d = fatorial (a);
	printf ("\n8-%.1f,", d);
	d = fatorial (b);
	printf (" %.1f", d);
	d = fatorial (c);
	printf (" e %.1f", d);
	
	//Ex.9
	a = 3;
	b = 5;
	c = 20;
	int resp = somaNumerosDiv3ou5 (a);
	printf ("\n9-A soma eh: %d", resp);
	resp = somaNumerosDiv3ou5 (b);
	printf (" %d", resp);
	resp = somaNumerosDiv3ou5 (c);
	printf (" %d", resp);
	
	//Ex.10 - Não precisa testar
	
	//Ex.11  
	int nndiv = 66;
	int ndiv = numeroDivisores (nndiv);
	printf ("\n11-O numero tem %d divisores", ndiv);
	
	//Ex.12
	a = 3;
	b = 4;
	c = 7;
	fa = enesimoFibonacci (a);
	fb = enesimoFibonacci (b);
	fc = enesimoFibonacci (c);
	printf ("\nO termo 3 = %d, o termo 4 = %d e o termo 7 = %d", fa, fb, fc);
	
	//Ex.13
	a = 18;
	b = 6;
	resp = mdc (a, b);
	printf ("\n13-MDC = %d", resp);
	
	//Ex.14
	a = 18;
	b = 12;
	resp = mmc (a, b);
	printf ("\n14-MMC = %d", resp);
	
	//Ex.15 é programa
}

