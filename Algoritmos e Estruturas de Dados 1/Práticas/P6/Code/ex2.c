#include <stdio.h>
#include <ctype.h>
#include <conio.h>


void main (){
	int nota;
	printf ("Nota do aluno (de 0 a 10): ");
	scanf ("%d", &nota);
	switch (nota){
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
		printf ("Conceito F");
		break;
	case 5:
		printf ("Conceito E");
		break;
	case 6:
		printf ("Conceito D");
		break;
	case 7:
		printf ("Conceito C");
		break;
	case 8:
		printf ("Conceito B");
		break;
	case 9:
	case 10:
		printf ("Conceito A");
		break;
	default:
		printf ("Nao se aplica");
	}
	
}