#include <stdlib.h>
#include <stdio.h>
#include "jogo.h"

//1.3)
void criaGuerreiro(Guerreiro *g){
	(*g).ataque = rolaDados();
	(*g).defesa = rolaDados();
	(*g).carisma = rolaDados();
	int aux = rolaDados() + rolaDados() + rolaDados();
	(*g).pontos_vida = aux;
}

//1.2)
int rolaDados(){
	int dado1 = 1+rand()%6;
	int dado2 = 1+rand()%6;
	int dado3 = 1+rand()%6;
	int soma = dado1+dado2+dado3;
}

//1.4)
int bonusCarisma (int c){
	switch (c){
		case 18:
			return 3;
			break;
		case 16:
			return 2;
			break;
		case 17:
			return 2;
			break;
		case 14:
			return 1;
			break;
		case 15:
			return 1;
			break;
		case 6:
			return -1;
			break;
		case 7:
			return -1;
			break;
		case 4:
			return -2;
			break;
		case 5:
			return -2;
			break;
		case 3:
			return -3;
			break;
		default:
			return 0;
	}
}

//1.5)
void ataca (Guerreiro *g1, Guerreiro *g2){
	//golpe do g1
	int golpe = rolaDados() + (*g1).ataque + bonusCarisma ((*g1).carisma);
	printf ("\nGolpe do %d: %d",(*g1).id_jogador, golpe);
	//escudo do g2
	int escudo = rolaDados() + (*g2).defesa + bonusCarisma ((*g2).carisma);
	printf ("\nEscudo do %d: %d",(*g2).id_jogador, escudo);
	int dano = golpe - escudo;
	if (dano > 0){
		(*g2).pontos_vida -= dano;
	}
	printf ("\nDano sobre %d: %d",(*g2).id_jogador, dano);
	printf ("\nPontos de vida do %d: %d", (*g2).id_jogador, (*g2).pontos_vida);
}







