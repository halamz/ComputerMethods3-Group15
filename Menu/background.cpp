#include "background.h"


background::background()
{

}

void background::setBorder()
{
	al_draw_rectangle(90, 90, 1210 - 40, 710 - 40, al_map_rgb(0, 0, 255), 10);
}

void background::setBlocks()
{
	al_draw_filled_rectangle(140 + (40 * 2), 140 + (40 * 2), 140 + (40 * 4), 140 + (40 * 4), al_map_rgb(0, 0, 255));
	al_draw_filled_rectangle(140 + (40 * 2), 140 + (40 * 8), 140 + (40 * 4), 140 + (40 * 10), al_map_rgb(0, 0, 255));
	al_draw_filled_rectangle(140 + (40 * 8), 140 + (40 * 2), 140 + (40 * 10), 140 + (40 * 10), al_map_rgb(0, 0, 255));
	al_draw_filled_rectangle(140 + (40 * 8), 140 + (40 * 2), 140 + (40 * 14), 140 + (40 * 4), al_map_rgb(0, 0, 255));
	al_draw_filled_rectangle(140 + (40 * 18), 140 + (40 * 2), 140 + (40 * 22), 140 + (40 * 4), al_map_rgb(0, 0, 255));
	al_draw_filled_rectangle(140 + (40 * 14), 140 + (40 * 8), 140 + (40 * 16), 140 + (40 * 10), al_map_rgb(0, 0, 255));
	al_draw_filled_rectangle(140 + (40 * 20), 140 + (40 * 8), 140 + (40 * 22), 140 + (40 * 10), al_map_rgb(0, 0, 255));
}
background::~background()
{
}
