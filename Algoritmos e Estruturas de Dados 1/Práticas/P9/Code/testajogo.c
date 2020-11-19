#include "jogo.h"
#include <stdio.h>

void main(){
	Guerreiro g1, g2;
	g1.id_jogador = 1;
	g2.id_jogador = 2;
	criaGuerreiro (&g1);
	criaGuerreiro (&g2);
	printf ("Id: %d, Ataque: %d, Defesa: %d, Carisma: %d, Pontos de vida: %d",g1.id_jogador, g1.ataque, g1.defesa, g1.carisma, g1.pontos_vida);
	printf ("\nId: %d, Ataque: %d, Defesa: %d, Carisma: %d, Pontos de vida: %d",g2.id_jogador, g2.ataque, g2.defesa, g2.carisma, g2.pontos_vida);
	while (g1.pontos_vida > 0 && g2.pontos_vida > 0){
		if (g2.pontos_vida > 0){
			ataca (&g1, &g2);
		}
		if (g1.pontos_vida > 0){
			ataca (&g2, &g1);
		}
	}
	if (g1.pontos_vida > g2.pontos_vida){
		printf ("\nO vencedor eh o id: %d", g1.id_jogador);
	}
	else {
		printf ("\nO vencedor eh o id: %d", g2.id_jogador);
	}
	printf ("\nPontos de vida do id 1: %d", g1.pontos_vida);
	printf ("\nPontos de vida do id 2: %d", g2.pontos_vida);
}