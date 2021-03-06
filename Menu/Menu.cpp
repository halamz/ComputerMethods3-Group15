#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include "Player.h"
#include "background.h"

using namespace std;

int main(int argc, char **argv){

	Player pacman;

	if (!al_init()){
		return -1;
	}

	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf (True Type Font) addon

	ALLEGRO_DISPLAY *display = al_create_display(1200, 720);
	al_set_window_position(display, 0, 0);

	if (!display){
		return -1;
	}

	ALLEGRO_FONT *font = al_load_ttf_font("PAC-FONT.ttf",100, 0);
	ALLEGRO_FONT *font1 = al_load_ttf_font("ArcadeClassic.ttf", 45, 0);
	ALLEGRO_FONT *font2 = al_load_ttf_font("ArcadeClassic.ttf", 45, 0);
	ALLEGRO_FONT *font3 = al_load_ttf_font("ArcadeClassic.ttf", 45, 0);
	
	if (!font){
		return -1;
	}

	if (!font1){
		return -1;
	}

	if (!font2){
		return -1;
	}

	if (!font3){
		return -1;
	}


    al_clear_to_color(al_map_rgb(0, 0, 0)); //background colour 
	string name = "score";

	al_draw_text(font, al_map_rgb(255, 255, 0), 640, 120, ALLEGRO_ALIGN_CENTRE, "PACMAN");
	al_draw_text(font1, al_map_rgb(255, 255, 255), 640, 650,ALLEGRO_ALIGN_CENTRE,"ABOUT");
	al_draw_text(font2, al_map_rgb(255, 255, 255), 640, 600, ALLEGRO_ALIGN_CENTRE, "CONTROLS");
	al_draw_text(font3, al_map_rgb(255, 255, 255), 640, 550, ALLEGRO_ALIGN_CENTRE, "START GAME");

		ALLEGRO_BITMAP  *image = NULL;

		if (!al_init_image_addon()) {
				(NULL, ALLEGRO_MESSAGEBOX_ERROR);
			return 0;
		}

		image = al_load_bitmap("pacman1.png");

		if (!image) {
				(NULL, ALLEGRO_MESSAGEBOX_ERROR);
			return 0;
		}

		al_draw_bitmap(image, 420,300, 0);

		al_flip_display();
		
		
		pacman.showPlayer();

		al_destroy_display(display);
		al_destroy_bitmap(image);

	return 0;
}
