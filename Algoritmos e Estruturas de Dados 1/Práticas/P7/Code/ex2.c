#include <stdio.h>

void main(){
	int n;
	int i;
	int fib, fib_1 = 1, fib_2 = 1;
	int vetfib [1001];
	vetfib [0] = 0;
	vetfib [1] = 1;
	vetfib [2] = 1;
	for (i=3; i<1001; i++){
		vetfib [i] = fib_1 + fib_2;
		fib_2 = fib_1;
		fib_1 = vetfib [i];
	}
	do{
	printf ("\nEscolha um termo da sequencia: ");
	scanf ("%d", &n); 
	printf ("O termo na posicao %d eh %d", n, vetfib[n]);
	}
	while (n >= 0 && n < 1000);
	//for (i=0;i<1001; i++){
	//	printf ("%d ", vetfib [i]);
	//}
}
