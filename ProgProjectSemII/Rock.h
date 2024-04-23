// Rock class declaration
#pragma once

#include "SFML/Graphics.hpp"
#include "Globals.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

class Rock
{
	// the rock used by the player

	sf::Texture texture; // texture used for the rock
	sf::Sprite sprite; // sprite used for the rock

	int direction; // the direction the rock is going
	int enemyDirection;
	int speed; // how fast the rock is being thrown

	bool isFired = false; // is the rock fired.

	sf::Vector2f location;


public:
	Rock(); // constructor

	void loadImage(); // loads the content from the image files

	sf::Sprite getBody();

	//void setUpRock(sf::Vector2f& enemyPos, Enemy enemies);
	void setPosition(sf::Vector2f& position); 
	void move();// moves the rock

	void fired(Player myPlayer);
	void reset(Player myPlayer);

	bool isActive; // is the rock active
	

};

