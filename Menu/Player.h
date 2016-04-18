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
	//mutator methods
	void setPosx(int );		//method to set position x
	void setPosy(int );		//method to set position y
	void setScore(int);		//method to set the score
	void setLives();			//method to set the lives
	~Player();		//defualt destructor
};

