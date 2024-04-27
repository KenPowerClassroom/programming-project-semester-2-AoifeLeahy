// Player class declaration
#pragma once

#include "Globals.h"
#include "SFML/Graphics.hpp"

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
	int health;
	bool alive;
	
	bool movingRight = true;
	bool movingDown = true;


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

	sf::Vector2f getPosition();
	int getDirection();
		
	void decreaseLives(); // this makes the players lives decrease when any collision happens
	
	void setAlive(int newAlive);
	int getAlive(); // this makes it return if alive or not

	void reset();

	void moveEnemyGuard(); // moves the enemy up and down while staying in the boundary of the screen


};
