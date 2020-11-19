//1.1)
typedef struct Guerreiro {
	int ataque, defesa, carisma, pontos_vida, id_jogador;
} Guerreiro;

int rolaDados();

void criaGuerreiro(Guerreiro *g);

void ataca (Guerreiro *g1, Guerreiro *g2);

int bonusCarisma (int c);