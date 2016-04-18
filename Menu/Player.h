#pragma once
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <iostream>

class Player
{
private:
	int pos_x;		//keep track of the player's x position
	int pos_y;		//keep track of the player's y position
	int pos_r;		//keep track of the player's radius
	int score;		//keep track of the player's score
	int lives;		//keep track of the player's live count
public:
	Player();		//default constructor

	~Player();		//defualt destructor
};

