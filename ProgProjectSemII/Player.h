// Player class declaration
#pragma once

#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class Player
{
	sf::Texture texture; // the texture for the player 
	sf::Sprite sprite; // sprite used to represent the player

	int score; // player score
	int noOfLives; // number of lives the player has. When reaches 0, player dies.
	int direction; // the direction in which the player is facing
	int speed; // player speed

	// private data members

public:
	Player(); // default constructer
	void loadImage(); // loads the image

	sf::Sprite getBody();
	void setPosition();
	void setPosition(int xPos, int yPos);

	void draw(); // used to draw the player in the game
	void shootRock(); // this is the function used to cause the rock to shoot
	void loadContent(); // this loads the content in the player image files
	void dies(); // used when the player dies and loses the game

	void moveRight(); // used to move the player to the right but withing the boundary of the screen
	void moveLeft(); // player moves left
	void moveDown(); // player moves down
	void moveUp(); // player moves up.
	void displayPlayerStats(); // display the players score and lives
	void increaseScore(); // the player's score increases
	void decreaseLives(); // the player's lives decreases


};
