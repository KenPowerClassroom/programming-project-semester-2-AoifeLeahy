// Rock class declaration
#pragma once

#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "Player.h"
#include <iostream>

class Rock
{
	// the rock used by the player

	sf::Texture texture; // texture used for the rock
	sf::Sprite sprite; // sprite used for the rock
	sf::Vector2f velocity;

	int direction; // the direction the rock is going
	int speed; // how fast the rock is being thrown

	bool isFired; // is the rock fired.


public:
	Rock(); // constructor

	void loadImage(); // loads the content from the image files

	sf::Sprite getBody();

	void draw(); // used to draw the rock
	void update();

	void hit(); // used if the rock hits something
	void move();// moves the rock

	void fired(Player myPlayer);

	bool isActive; // is the rock active
	

};

