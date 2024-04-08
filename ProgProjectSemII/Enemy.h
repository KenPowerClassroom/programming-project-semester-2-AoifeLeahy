// Player class declaration
#pragma once

#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class Enemy
{
	// this enemy protects the key from the player

	sf::Texture texture; // texture used for enemy 
	sf::Sprite sprite; // sprite used for enemy

	int direction; // direction of enemy
	int speed; // enemy speed
	int timesHit; // number of times the enemy is hit
	//int initialPosx; 
	int imageWidth; // the width of the pixels of the enemy image

	// private data members

public:
	Enemy(); // constructer
	void loadImage(); // loads the image

	sf::Sprite getBody();
	void setPosition();
	void setPosition(int xPos, int yPos);


	void loadContent(); // used to load content in the player image files
	void draw(); // draws the enemy
	void dies(); // used if the enemy dies
	void moveEnemies(Enemy enemy[], int MAX_ENEMIES); // used to move the enemy up while staying in the boundary of the screen
	void hit(); // if the enemy is hit by the rock

};
	


