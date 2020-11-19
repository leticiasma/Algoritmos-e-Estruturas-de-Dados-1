#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define BUFFER_TAM 5

int main ()
{
	int countBuffer = 0,total = 0;
	char c,buffer[BUFFER_TAM],*texto,*textoaux;
	do 
	{
		c = getche();
		if (c == '\r')
		{
			c = '\n';
			printf ("\n");
		}
		if (countBuffer < BUFFER_TAM)
			buffer[countBuffer++] = c;
		
		if (countBuffer == BUFFER_TAM || c == '#')
		{
			textoaux = (char*)malloc((total + countBuffer)*sizeof(char));
			
			int i;
			int j = 0;
			for (i = 0; i < total; i++)
				*(textoaux + j++) = *(texto + i);
			for (i = 0; i < countBuffer; i++)
				*(textoaux + j++) = buffer[i];
			total += countBuffer;
			free(texto);
			texto = textoaux;
			countBuffer = 0;
		}
	}
	while (c != '#');
	texto[total-1] = '\0';
	printf ("\n");
	int i;
	for (i = 0; i < total; i++)
		printf ("%c", *(texto + i));
	free(texto);
	return 0;
}