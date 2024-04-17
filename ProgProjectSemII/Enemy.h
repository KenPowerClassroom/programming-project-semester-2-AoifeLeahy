// Player class declaration
#pragma once

#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class Enemy
{
	// this enemy protects the key from the player

	sf::Texture upTexture; // up texture used for enemy 
	sf::Texture downTexture; // down texture for enemy
	sf::Texture rightTexture; // right texture for enemy
	sf::Texture leftTexture; // left texture for enemy

	sf::Sprite sprite; // sprite used for enemy

	int direction; // direction of enemy
	int speed; // enemy speed
	int timesHit; // number of times the enemy is hit
	 
	int imageWidth; // the width of the pixels of the enemy image
	int imageHeight; // the height of the pixels of the enemy image

	int initialPosX; 
	int initialPosY;

	// private data members

public:
	Enemy(); // constructer
	void loadImage(); // loads the image

	sf::Sprite getBody();
	void setPosition();
	void setPosition(int xPos, int yPos);


	void draw(); // draws the enemy
	void dies(); // used if the enemy dies
	void moveEnemies(); // used to move the enemy up while staying in the boundary of the screen
	void hit(); // if the enemy is hit by the rock

	bool movingRight; 
	bool movingUp;
	

};
	


