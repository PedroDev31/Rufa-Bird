#include <allegro.h>
#include <stdio.h>
#include "princ.h"
#include "menu.h"




int main() {
	
	//inicio do codigo
	allegro_init();
	install_timer();
	install_keyboard();
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 940,560,0,0);
	set_window_title("Trabalho allegro");

	
	BITMAP *buffer =create_bitmap(940,560);

    menu();

	destroy_bitmap(buffer);
	
	
	return 0;
}
END_OF_MAIN();

