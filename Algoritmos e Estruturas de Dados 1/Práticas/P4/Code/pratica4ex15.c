#include "pratica4.h"
#include <stdio.h>

void main (){
	int a;
	int b;
	do {
		scanf ("%d %d", &a, &b);
	}
	while (a <= 0 || b <= 0); //Se tirar o ; fica meio sem sentido o comando, sem "continuação"
	int MDC = mdc (a, b);
	int MMC = mmc (a, b);
	printf ("MDC = %d e MMC = %d", MDC, MMC); 
	
}