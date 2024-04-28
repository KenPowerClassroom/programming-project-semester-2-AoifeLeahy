// Player class declaration
#pragma once

#include "SFML/Graphics.hpp"
#include "Globals.h"
#include <iostream>

class Player
{
	sf::Texture upTexture; // the texture for the player facing upwards
	sf::Texture downTexture; // the texture for the player facing upwards
	sf::Texture leftTexture; // the texture for the player facing upwards
	sf::Texture rightTexture; // the texture for the player facing upwards
	sf::Sprite sprite; // sprite used to represent the player

	int imageWidth; // the width of the player 
	int imageHeight; //  the height of the player
	int score; // player score
	int health; // number of lives the player has. When reaches 0, player dies.
	int direction; // the direction in which the player is facing
	int speed; // player speed

	bool alive; // is the player alive or dead in the game
	// private data members

public:
	Player(); // default constructer
	void loadImage();  // this loads the content in the player image files

	sf::Sprite getBody();
	void setPosition();
	void setPosition(int xPos, int yPos);
	
	sf::Vector2f getPosition(); 

	int getDirection(); 
	
	void update();

	void moveRight(); // used to move the player to the right but withing the boundary of the screen
	void moveLeft(); // player moves left
	void moveDown(); // player moves down
	void moveUp(); // player moves up.

	void setAlive(int newAlive);
	int getAlive();

	void displayPlayerStats(); // display the players score and lives
	void increaseScore(); // the player's score increases
	void decreaseLives(); // the player's lives decreases

	void reset();


};
