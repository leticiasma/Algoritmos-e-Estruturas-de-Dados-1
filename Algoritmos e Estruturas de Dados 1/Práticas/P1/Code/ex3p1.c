#include <stdio.h>
#include <math.h>

	void main ()
	{
	float imc_brut = 122/(1.84*1.84);
	printf ("O IMC de Brutus e: %.2f", imc_brut);
	float imc_ol = 45/(1.76*1.76);
	printf (" e o IMC de Olivia e: %.2f \n", imc_ol);
	//Perda ideal de Brutus
	float perda_brut = 122-25*1.84*1.84;
	printf ("Brutus deve perder no minimo, aproximadamente, %.0f kg", perda_brut);
	//Ganho ideal de Olívia
	float ganho_ol = 18.5*1.76*1.76-45;
	printf (" e Olivia deve ganhar no minimo, aproximadamente, %.0f kg", ganho_ol);
	
	}