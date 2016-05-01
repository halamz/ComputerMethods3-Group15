#pragma once
#include <stdio.h>
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"
#include <string>
using namespace std;

enum KEYS{ DOWN, UP, RIGHT, LEFT };

class Player
{
private:
	int pos_x;		//keep track of the player's x position
	int pos_y;		//keep track of the player's y position
	int pos_r;		//keep track of the player's radius
	int score;		//keep track of the player's score
	int lives;		//keep track of the player's live count
	int path[7][13];
public:
	Player();		//default constructor
	//mutator methods
	void setPosx(int );		//method to set position x
	void setPosy(int );		//method to set position y
	void setScore(int);		//method to set the score
	void setLives();		//method to set the lives

	//acessor methods
	int getPosx();
	int getPosy();
	int getScore();
	int getLives();

	void diplayScore();
	void setPath();
	void showPlayer();
	~Player();		//defualt destructor
};

