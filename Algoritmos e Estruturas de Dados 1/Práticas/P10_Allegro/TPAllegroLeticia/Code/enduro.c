#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <math.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#define NUMCARS 10

int pintaceu;
int c1 = 35 ,c2 = 35 ,c3 = 142 ;

FILE *arquivo_recorde;
int recorde = 0;

const float FPS = 100;
const int SCREEN_W = 960;
const int SCREEN_H = 540;

float CAR_W = 100;
float CAR_H = 10;
float WHEEL_W = 30;
float WHEEL_H = 30;

//Carros inimigos
int i;
float tam_0 = 10;
float alt_0 = 1;
float roda_w0 = 3;
float roda_h0 = 3;
float dist, xc, taxa;
int col;

float THETA;
int score = 0;

int SKY_H;
float TRACK_TOP_W;
float TRACK_BOTTOM_W;

float TRACK_TOP_LEFT_X;
float TRACK_TOP_LEFT_Y;
float TRACK_BOTTOM_LEFT_X;
float TRACK_BOTTOM_LEFT_Y;

float TRACK_TOP_RIGHT_X;
float TRACK_TOP_RIGHT_Y;
float TRACK_BOTTOM_RIGHT_X;
float TRACK_BOTTOM_RIGHT_Y;

ALLEGRO_FONT *size_32 = NULL;


//Carro principal
float x_centro, y_centro;
int moveesq, movedir;


//Composição carros inimigos
typedef struct Car {
	float x, y, acel; //Coordenadas do centro
	int R, G, B;
	float tam, tamr, alt, altr;
} Car;

//Sorteia uma cor
int sorteiacor(){
	return rand()%256;
}

//Sorteia um float aleatório entre min e max
float numfloat (int min, int max){
	float num =((float)(min+rand()%max))+((float)(rand()%(max*100))/100);
	//printf ("%f ", num);
	return num;
}

//Desenha os inimigos
void criaCarro(Car *c, float x){
	if ((*c).y>SKY_H+(CAR_H/2)){
		al_draw_filled_rectangle(x-((*c).tam/2), (*c).y-((*c).alt/2), x+((*c).tam/2), (*c).y+((*c).alt/2), al_map_rgb((*c).R,(*c).G,(*c).B));
		al_draw_filled_rectangle(x-(((*c).tam/2)+(*c).tamr), (*c).y-((*c).altr/2), x-((*c).tam/2), (*c).y+((*c).altr/2), al_map_rgb(0,0,0));
		al_draw_filled_rectangle(x+((*c).tam/2), (*c).y-((*c).altr/2), x+(((*c).tam/2)+(*c).tamr), (*c).y+((*c).altr/2), al_map_rgb(0,0,0));
	}
}

//Vetor de carros inimigos
Car inim[NUMCARS];

//Proporção de crescimento
float getRatio (float y){
		float ratio = y/tan(THETA);
		return ratio/(TRACK_BOTTOM_W/2);

}

//Módulo
float modulo(float n){
	if (n<0){
		return -n;
	}
	else{
		return n;
	}
}

//Testa colisão
int colisao (Car *inim, float x){
	if (y_centro-(*inim).y<(WHEEL_H/2)+((*inim).altr/2)){
		if (modulo(x_centro-(*inim).x)<(((CAR_W/2)+((*inim).tam/2))+WHEEL_W+(*inim).tamr)){
			return 1;
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
}

void init_global_vars() {

	SKY_H = SCREEN_H/4;

	TRACK_TOP_W = SCREEN_W/100;
	TRACK_BOTTOM_W = SCREEN_W/1.2;

	TRACK_TOP_LEFT_X = SCREEN_W/2 - TRACK_TOP_W/2;
	TRACK_TOP_LEFT_Y = SKY_H;
	TRACK_BOTTOM_LEFT_X = SCREEN_W/2 - TRACK_BOTTOM_W/2;
	TRACK_BOTTOM_LEFT_Y = SCREEN_H;

	TRACK_TOP_RIGHT_X = SCREEN_W/2 + TRACK_TOP_W/2;
	TRACK_TOP_RIGHT_Y = SKY_H;
	TRACK_BOTTOM_RIGHT_X = SCREEN_W/2 + TRACK_BOTTOM_W/2;
	TRACK_BOTTOM_RIGHT_Y = SCREEN_H;

	//Ângulo referência da pista
	THETA = atan((TRACK_BOTTOM_LEFT_Y - TRACK_TOP_LEFT_Y)/(TRACK_TOP_LEFT_X - TRACK_BOTTOM_LEFT_X));

	//Centro do carro principal
	x_centro = SCREEN_W/2;
	y_centro = SCREEN_H-(WHEEL_H/2);

	for (i=0;i<NUMCARS;i++){
		inim[i].R = sorteiacor();
		inim[i].G = sorteiacor();
		inim[i].B = sorteiacor ();
		inim[i].x = numfloat ((int)TRACK_BOTTOM_LEFT_X,((int)TRACK_BOTTOM_RIGHT_X-TRACK_BOTTOM_LEFT_X));
		inim[i].y = numfloat (-800, (int)(SKY_H+(CAR_H/2)));
		inim[i].acel = numfloat(1,1.8);
		inim[i].tam = tam_0;
		inim[i].alt = alt_0;
		//printf ("%f ", inim[i].acel);
	}
}

void draw_scenario(ALLEGRO_DISPLAY *display) {

	//grass
	ALLEGRO_COLOR BKG_COLOR = al_map_rgb(35,142,35);
	al_set_target_bitmap(al_get_backbuffer(display));
	al_clear_to_color(BKG_COLOR);

	//sky
	al_draw_filled_rectangle(0, 0, SCREEN_W, SKY_H, al_map_rgb(c1,c2,c3));
	al_draw_filled_circle(350.0, 50.0, 45.0, al_map_rgb(255, 255, 255));
	al_draw_filled_triangle(0, SKY_H, 30, SKY_H-40, 60, SKY_H, al_map_rgb(92, 51, 23));
	al_draw_filled_triangle(60, SKY_H, 90, SKY_H-60, 120, SKY_H, al_map_rgb(92, 51, 23));
    al_draw_filled_triangle(960, SKY_H, 910, SKY_H-80, 860, SKY_H, al_map_rgb(92, 51, 23));
	al_draw_filled_triangle(860, SKY_H, 840, SKY_H-60, 820, SKY_H, al_map_rgb(92, 51, 23));
	al_draw_filled_triangle(820, SKY_H, 790, SKY_H-20, 760, SKY_H, al_map_rgb(92, 51, 23));

   //desenha a pista:
   al_draw_line(TRACK_TOP_LEFT_X, TRACK_TOP_LEFT_Y, TRACK_BOTTOM_LEFT_X, TRACK_BOTTOM_LEFT_Y, al_map_rgb(105,105,105), 10);
   al_draw_line(TRACK_TOP_RIGHT_X, TRACK_TOP_RIGHT_Y, TRACK_BOTTOM_RIGHT_X, TRACK_BOTTOM_RIGHT_Y, al_map_rgb(105,105,105), 10);

  //Desenha o carro principal
  al_draw_filled_rectangle(x_centro-(CAR_W/2), y_centro-(CAR_H/2), x_centro+(CAR_W/2), y_centro+(CAR_H/2), al_map_rgb(139,0,0));
  al_draw_filled_rectangle(x_centro-((CAR_W/2)+WHEEL_W), y_centro-(WHEEL_H/2), x_centro-(CAR_W/2), y_centro+(WHEEL_H/2), al_map_rgb(0,0,0));
  al_draw_filled_rectangle(x_centro+(CAR_W/2), y_centro-(WHEEL_H/2), x_centro+((CAR_W/2)+WHEEL_W), y_centro+(WHEEL_H/2), al_map_rgb(0,0,0));

  //Desenha inimigos
  for (i=0;i<NUMCARS;i++){
		dist = (inim[i].y-SKY_H);
		taxa = getRatio(dist);
		inim[i].y+=1*inim[i].acel;
		//printf ("%f ", taxa);
		inim[i].tam = CAR_W*taxa;
		inim[i].alt = CAR_H*taxa;
		inim[i].altr = WHEEL_H*taxa; 
		inim[i].tamr = WHEEL_W*taxa;
		xc = (SCREEN_W/2)+((inim[i].x-(SCREEN_W/2))*taxa);
		//printf ("%f ", inim[i].x);
		criaCarro(&inim[i], xc);
	}

	al_draw_textf(size_32, al_map_rgb(255, 255, 255), 10, 10, 0, "Score: %d", score);
}

int main(int argc, char **argv){
	
	arquivo_recorde = fopen("recorde.txt", "r");
	fscanf(arquivo_recorde, "%d ", &recorde);
	fclose(arquivo_recorde);
	//printf ("%d ", recorde);
	
	//srand(time(NULL));
	srand(2);
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_AUDIO_STREAM *trilha = NULL;

	init_global_vars();

	//----------------------- rotinas de inicializacao ---------------------------------------
   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

    if(!al_init_primitives_addon()){
		fprintf(stderr, "failed to initialize primitives!\n");
        return -1;
    }

   timer = al_create_timer(1.0 / FPS);
   if(!timer) {
      fprintf(stderr, "failed to create timer!\n");
      return -1;
   }

   display = al_create_display(SCREEN_W, SCREEN_H);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      al_destroy_timer(timer);
      return -1;
   }

	//inicializa o modulo allegro que carrega as fontes
    al_init_font_addon();
	//inicializa o modulo allegro que entende arquivos tff de fontes
    al_init_ttf_addon();
	//carrega o arquivo arial.ttf da fonte Arial e define que sera usado o tamanho 32 (segundo parametro)
    	size_32 = al_load_font("arial.ttf", 32, 0);


   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_display(display);
      al_destroy_timer(timer);
      return -1;
   }
   
   al_install_keyboard();
   al_install_audio();
   al_init_acodec_addon();
   al_reserve_samples(2);
   trilha = al_load_audio_stream ("jogomus.ogg", 4, 1024);
	al_set_audio_stream_playmode (trilha, ALLEGRO_PLAYMODE_LOOP);
	al_attach_audio_stream_to_mixer(trilha, al_get_default_mixer());
	al_set_audio_stream_playing(trilha,true);
   

	//registra na fila de eventos que eu quero identificar quando a tela foi alterada
   al_register_event_source(event_queue, al_get_display_event_source(display));
	//registra na fila de eventos que eu quero identificar quando o tempo alterou de t para t+1
   al_register_event_source(event_queue, al_get_timer_event_source(timer));

   al_register_event_source(event_queue, al_get_keyboard_event_source());

	//reinicializa a tela
   al_flip_display();
	//inicia o temporizador
   al_start_timer(timer);

   int playing = 1;
	//enquanto playing for verdadeiro, faca:
   while(playing) {
      ALLEGRO_EVENT ev;
	  //espera por um evento e o armazena na variavel de evento ev
      al_wait_for_event(event_queue, &ev);

	if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
		//verifica qual tecla foi
		switch(ev.keyboard.keycode){
			//se a tecla for o M
			case ALLEGRO_KEY_M: //ALTERAÇÃO SUGERIDA PARA AVALIAÇÃO
			pintaceu = 1;
			
			break;
			//se a tecla for o S
			case ALLEGRO_KEY_S:

			break;

			case ALLEGRO_KEY_A:
			moveesq = 1;

			break;

			case ALLEGRO_KEY_D:
			movedir = 1;

			break;

			case ALLEGRO_KEY_ESCAPE:
				playing = 0;
			break;
		}

	}
	else if(ev.type == ALLEGRO_EVENT_KEY_UP){
		//verifica qual tecla foi
		switch(ev.keyboard.keycode){
			case ALLEGRO_KEY_M:
			pintaceu = 0;

			break;
			//se a tecla for o S
			case ALLEGRO_KEY_S:

			break;

			case ALLEGRO_KEY_A:
			moveesq = 0;

			break;

			case ALLEGRO_KEY_D:
			movedir = 0;

			break;
		}
	}

	//se o tipo de evento for um evento do temporizador, ou seja, se o tempo passou de t para t+1
    else if(ev.type == ALLEGRO_EVENT_TIMER) {
		
		if (pintaceu){
			c1 = rand()%256;
			c2 = rand()%256;
			c3 = rand()%256;
		}

		if (moveesq && x_centro-((CAR_W/2)+WHEEL_W) >= TRACK_BOTTOM_LEFT_X){
		x_centro-=3;
		}

		if (movedir && x_centro+((CAR_W/2)+WHEEL_W) <= TRACK_BOTTOM_RIGHT_X){
		x_centro+=3;
		}
		
		for (i=0;i<NUMCARS;i++){
			if(inim[i].y-inim[i].alt>SCREEN_H){
				score++;
				inim[i].R = sorteiacor();
				inim[i].G = sorteiacor();
				inim[i].B = sorteiacor ();
				inim[i].x = (float)(rand()%(int)(TRACK_BOTTOM_RIGHT_X - TRACK_BOTTOM_LEFT_X + 1) + TRACK_BOTTOM_LEFT_X);
				inim[i].y = numfloat(-800, (int)(SKY_H+(CAR_H/2)));
				inim[i].acel = numfloat(1,1.8);
				//printf ("%f ", inim[i].acel);
				inim[i].tam = tam_0;
				inim[i].alt = alt_0;
				inim[i].altr = roda_h0;
				inim[i].tamr = roda_w0;
				criaCarro(&inim[i], inim[i].x);
			}
			if (colisao(&inim[i],x_centro)){
				//printf ("%d ", score);
				col = 1;
				playing = 0;
			}
		}
		
		draw_scenario(display);

		//reinicializo a tela
		 al_flip_display();
	}
	//se o tipo de evento for o fechamento da tela (clique no x da janela)
	else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		playing = 0;
	}

  } //fim do while
	al_clear_to_color(al_map_rgb(0,0,0));
	if (score>recorde){
		arquivo_recorde = fopen("recorde.txt", "w");
		fprintf(arquivo_recorde, "%d", score);
		//printf ("%d ", recorde);
		fclose (arquivo_recorde);
		al_draw_textf(size_32, al_map_rgb(255, 255, 255), 10, 100, 0, "Novo recorde: %d", score);
	}
	al_draw_textf(size_32, al_map_rgb(255, 255, 255), 10, 10, 0, "Score: %d", score);
	al_draw_textf(size_32, al_map_rgb(255, 255, 255), 10, 50, 0, "Recorde anterior: %d", recorde);
	

	
	//reinicializa a tela
	al_flip_display();
    al_rest(3);


   al_destroy_timer(timer);
   al_destroy_display(display);
   al_set_audio_stream_playing(trilha,false);
   al_destroy_audio_stream(trilha);
   al_destroy_event_queue(event_queue);


   return 0;
}
