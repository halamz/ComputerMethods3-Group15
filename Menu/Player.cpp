#include "Player.h"
#include "background.h"

Player::Player()
{

	pos_x = 140;		//set player's initial x position
	pos_y = 140;		//set the player's initial y position
	pos_r = 40;		//set the player's radius
	score = 0;		//set the player's initial score to 0
	lives = 3;		//set the player' lives to maximum
	setPath();
}
void Player::setPath()
{
	int temp[7][13] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 1 },
		{ 1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 1 },
		{ 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1 },
		{ 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};
	
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			path[i][j] = temp[i][j];
		}
	}

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
		lives -= 1;		//other wise decreases the number of lives left
}

void Player::setPosx(int x)
{
	if (path[(pos_x - 140) / 40][(pos_y - 140) / 40] != 2)
	{
		if (pos_x < 1140 && pos_x > 100)
			pos_x += x;
		if (pos_x == 1140)
			pos_x -= x;
		if (pos_x == 100)
			pos_x -= x;
	}
	else
		pos_x += x;
}

void Player::setPosy(int y)
{
	if (path[(pos_x - 140) / 40][(pos_y - 140) / 40] != 2)
	{
		if (pos_y < 660 && pos_y > 100)
			pos_y += y;
		if (pos_y == 660)
			pos_y -= y;
		if (pos_y == 100)
			pos_y -= y;
	}
	else
		pos_y += y;
}

//Accessor methods

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

void Player::diplayScore()
{
	al_init_font_addon(); // initialize the font addon
	al_init_ttf_addon();// initialize the ttf (True Type Font) addon

	ALLEGRO_FONT *font3 = al_load_ttf_font("ArcadeClassic.ttf", 45, 0);
	std::string sc = "score " + std::to_string(score);
	
	al_draw_text(font3, al_map_rgb(255, 255, 0), 400, 30, ALLEGRO_ALIGN_CENTRE, sc.c_str());

}

void Player::showPlayer()
{
	bool done = false;
	background back;
	bool keys[4] = { false, false, false, false };

	ALLEGRO_EVENT_QUEUE *event_queue = NULL;

	al_init_primitives_addon();
	al_install_keyboard();

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!done)
	{
		ALLEGRO_EVENT ev;

		al_wait_for_event(event_queue, &ev); //allegro waits for something to happend

		//creates the food
		for (int i = 0; i <= 12; i++)
		{
			for (int j = 0; j <= 6; j++)
			{
				if (path[j][i] == 1)
					al_draw_filled_circle(140 + (i * 80), 140 + (j * 80), 10, al_map_rgb(220, 0, 0));
			}
		}

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
			case  ALLEGRO_KEY_ESCAPE:
				done = true;
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
	

		setPosy(keys[UP] *-1* pos_r);
		setPosy(keys[DOWN] * pos_r);
		setPosx(keys[LEFT] * -1*pos_r);
		setPosx(keys[RIGHT] * pos_r);

		al_draw_filled_circle(getPosx(),getPosy(),pos_r, al_map_rgb(255, 255, 0));		//creates the player's face
		back.setBorder();
		back.setBlocks();
		// creates the player's mouth depending on the player's movement direction 
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

		//removes food 
		for (int i = 0; i <= 12; i++)
		{
			for (int j = 0; j <= 6; j++)
			{
				if (path[j][i] == 1 && pos_x == 140 + (i * 80) && pos_y == 140 + (j * 80))
				{
					path[j][i] = 0;
					setScore(10);
				}
			}
		}
		diplayScore();
		al_flip_display();		//flips the display screen
		al_clear_to_color(al_map_rgb(0, 0, 0));		//clears the diplay screen to black


	}

}

Player::~Player()
{
}
