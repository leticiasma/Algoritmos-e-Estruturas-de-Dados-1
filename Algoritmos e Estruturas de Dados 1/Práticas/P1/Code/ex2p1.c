#include <stdio.h>

	void main ()
	{
	
	float poup= 789.54;
	float juros = 1.0056;
	float mes2= poup * juros + 303.20;
	float mes3= mes2 * juros - 58.25;
	float mes4= mes3 * juros;
	printf ("No quarto mes a conta tera: %.2f reais", mes4 );
	
	
	}
	