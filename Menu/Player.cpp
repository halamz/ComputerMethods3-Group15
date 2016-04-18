#include "Player.h"


Player::Player()
{

	pos_x = 0;		//set player's initial x position
	pos_y = 0;		//set the player's initial y position
	pos_r = 10;		//set the player's radius
	score = 0;		//set the player's initial score to 0
	lives = 3;		//set the player' lives to maximum
}

void Player::setScore(int newscore)
{
	score += newscore;
}

void Player::setLives()
{
	if (lives == 1)
	{
		lives = 3; // end of game reset lives
		// -----code for call killplayer
	}
	else
		lives -= 1;
}

void Player::setPosx(int x)
{
	/*if (pos_x != 1200 && pos_x != 500)
		pos_x += x;
	if (pos_x == 1200)
		pos_x -= x;
	if (pos_x == 500)
		pos_x -= x; */

	pos_x += x;
}

void Player::setPosy(int y)
{
	/*if (pos_y != 700 && pos_y != 100)
		pos_y += y;
	if (pos_y == 700)
		pos_y -= y;
	if (pos_y == 100)
		pos_y -= y;  */

	pos_y += y;
}

int Player::getPosx()
{
	return pos_x;
}

int Player::getPosy()
{
	return pos_y;
}

int Player::getScore()
{
	return score;
}

int Player::getLives()
{
	return lives;
}

void Player::showPlayer()
{
	bool done = false;

	bool keys[4] = { false, false, false, false };

	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	al_init_primitives_addon();
	al_install_keyboard();

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done)
	{
		ALLEGRO_EVENT ev;

		al_wait_for_event(event_queue, &ev); //allegro, wait for something to happend (poor design for game development)

		if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				keys[UP] = true;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (ev.keyboard.keycode)
			{
			case ALLEGRO_KEY_UP:
				keys[UP] = false;
				break;
			case ALLEGRO_KEY_DOWN:
				keys[DOWN] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}

		setPosy(keys[UP] *-1* pos_r);
		setPosy(keys[DOWN] * pos_r);
		setPosx(keys[LEFT] * -1*pos_r);
		setPosx(keys[RIGHT] * pos_r);

		al_draw_filled_circle(getPosx(),getPosy(),pos_r, al_map_rgb(255, 255, 0));

		if (keys[DOWN])
		{
			al_draw_filled_triangle(getPosx(), getPosy(), getPosx() - pos_r, getPosy() + pos_r, getPosx() + pos_r, getPosy() + pos_r, al_map_rgb(0, 0, 0));
		}
		else if (keys[UP])
		{
			al_draw_filled_triangle(getPosx(), getPosy(), getPosx() - pos_r, getPosy() - pos_r, getPosx() + pos_r, getPosy() - pos_r, al_map_rgb(0, 0, 0));
		}
		else if (keys[LEFT])
		{
			al_draw_filled_triangle(getPosx(), getPosy(), getPosx() - pos_r, getPosy() + pos_r, getPosx() - pos_r, getPosy() - pos_r, al_map_rgb(0, 0, 0));

		}
		else if (keys[RIGHT])
		{
			al_draw_filled_triangle(getPosx(), getPosy(), getPosx() + pos_r, getPosy() + pos_r, getPosx() + pos_r, getPosy() - pos_r, al_map_rgb(0, 0, 0));
		}

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));


	}

}

Player::~Player()
{
}
