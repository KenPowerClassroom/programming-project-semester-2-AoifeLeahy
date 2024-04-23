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
	int health; // number of times the enemy is hit
	bool alive;
	 
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

	void moveEnemies(); // used to move the enemy up while staying in the boundary of the screen
	

	void setAlive(int newAlive);
	int getAlive(); // this makes it return if alive or not
	void decreaseLives();
	
	void reset();

};
	


