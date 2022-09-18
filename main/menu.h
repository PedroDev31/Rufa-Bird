#include <allegro.h>
#include <stdio.h>



void main() {
	
	allegro_init(); 
	install_keyboard();
	install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 940, 540, 0, 0);
	install_timer();
	
	
	BITMAP *buffer = create_bitmap(940, 540);
	BITMAP *logo = load_bitmap("Cenario Principal.bmp", NULL);
	
	
	int x = 225, y = 242;
	int botao = 1;
	
	
	while (!(  key[KEY_ESC])){
		clear(buffer);//primeira coisa a se fazer
		draw_sprite(buffer, logo, 0, 0);//desenhar o fundo

		BITMAP *selecione = load_bitmap("pre_menu2.bmp", NULL);
		
		switch (botao){
			case 1:
				x = 225;
				y = 242;
				rest (25);
				break;
				
			case 2:
				x = 640;
				y = 242;
				rest (25);
				break;
				
			case 3:
				x = 300;
				y = 310;
				rest (25);
				break;
				
			case 4:
				x = 578;
				y = 310;
				rest (25);
				break;
			
		}
		
		draw_sprite(buffer, selecione, x, y);
		
		if(key[KEY_RIGHT]) botao++; rest (25);
		if (botao > 4) botao = 1;
		if (botao < 1) botao = 4;
		
		if(key[KEY_LEFT]) botao --; rest (25);
		if (botao > 4) botao = 1;
		if (botao < 1) botao = 4;
		
		printf("botao : %d\n", botao);
		
		draw_sprite(screen, buffer, 0, 0);
		rest(10);
	}
}