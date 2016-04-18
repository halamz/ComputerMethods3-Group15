#include "Player.h"


Player::Player()
{

	pos_x = 0;		//set player's initial x position
	pos_y = 0;		//set the player's initial y position
	pos_r = 10;		//set the player's radius
	score = 0;		//set the player's initial score to 0
	lives = 3;		//set the player' lives to maximum
}


Player::~Player()
{
}
