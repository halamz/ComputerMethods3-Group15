#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

int main(int argc, char **argv){

	if (!al_init()){
		return -1;
	}

	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf (True Type Font) addon

	ALLEGRO_DISPLAY *display = al_create_display(1200, 820);

	if (!display){
		return -1;
	}

	ALLEGRO_FONT *font = al_load_ttf_font("PAC-FONT.ttf", 60, 0);
	ALLEGRO_FONT *font2 = al_load_ttf_font("Pacmania.ttf", 65, 0);


	if (!font){
		return -1;
	}

	if (!font2){
		return -1;
	}

	al_clear_to_color(al_map_rgb(0, 0, 0)); //background colour 
	al_draw_text(font, al_map_rgb(255, 255, 0), 640, (480 / 4), ALLEGRO_ALIGN_CENTRE, "PACMAN");
	al_draw_text(font2, al_map_rgb(255, 255, 0), 640, (480 / 2), ALLEGRO_ALIGN_CENTRE, "PACMAN");

	al_flip_display();

	al_rest(15.0);

	al_destroy_display(display);

	return 0;
}
