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
	if (pos_x != 1200 && pos_x != 100)
		pos_x += x;
	if (pos_x == 1200)
		pos_x -= x;
	if (pos_x == 100)
		pos_x -= x;
}

void Player::setPosy(int y)
{
	if (pos_y != 700 && pos_y != 100)
		pos_y += y;
	if (pos_y == 700)
		pos_y -= y;
	if (pos_y == 100)
		pos_y -= y;
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

Player::~Player()
{
}
