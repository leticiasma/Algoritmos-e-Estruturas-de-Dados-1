void troca(float *end_valor1, float *end_valor2) {
	float aux = *end_valor2;
	*end_valor2 = *end_valor1;
	*end_valor1 = aux;
}
