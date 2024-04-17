// Player class declaration
#pragma once

#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class EnemyGuard
{
	//this enemy moves up and down the screen in the game. Known as guards. Shoots at the player

	sf::Texture upTexture; // the texture for the enemy2 facing upwards
	sf::Texture downTexture; // the texture for the enemy2 facing upwards
	sf::Texture leftTexture; // the texture for the enemy2 facing upwards
	sf::Texture rightTexture; // the texture for the enemy2 facing upwards
	sf::Sprite sprite; // sprite used for second enemy that moves up and down

	int speed; // speed of enemy
	int direction; // enemy direction

	int imageWidth; // the width of the pixels of the enemy image
	int imageHeight; // the height of the pixels of the enemy image

	int initialPosX;
	int initialPosY; 

public: 
	EnemyGuard(); // constructor
	void loadImage();

	sf::Sprite getBody();
	void setPosition();
	void setPosition(int xPos, int yPos);

	void draw(); // draws the enemy
		
	void hit(); // enemy is hit by the rock
	void dies(); // enemy dies after being hit by the rock
	void shoots(); // enemy shoots a bullet
	void moveEnemyGuard(); // moves the enemy up and down while staying in the boundary of the screen

	bool movingRight;
	bool movingUp;
};
