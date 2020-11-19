#include <stdio.h>
#include <stdlib.h>

int main ()
{
	int n;
	int i,j;
	scanf ("%d", &n);
	float **matriz = (float**)malloc(sizeof(float*));
	//scanf ("%d", &n);
	for (i = 0; i < n;i++)
	{
		matriz[i] = (float*)malloc(n*sizeof(float));
		for (j = 0;j < n;j++)
		{
			matriz[i][j] = 0.0;
			printf ("%.1f ", matriz[i][j]);
		}
		printf ("\n");
	}
	free(matriz);
	return 0;
}