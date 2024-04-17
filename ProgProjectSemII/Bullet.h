// Bullet class declaration

#pragma once

#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class Bullet
{
	// the bullet used by the enemy

	sf::Texture bulletTexture; // texutre used for the bullet
	sf::Sprite sprite; // sprite used for the bullet

	sf::Vector2f velocity; 

	int direction; // direction of the bullet
	int speed; // the bullets speed
	bool isFired; // if the bullet is fired

public:
	Bullet(); // constructor

	sf::Sprite getBody();
	void setPosition();
	void setPosition(int xPos, int yPos);

	void loadImage(); // loads the content in the players image files
	void draw(); // draws the bullet
	void hit(); // if the bullet hits the player
	void fired(); // the bullet is fired
	void move(); // moves the bullet

};