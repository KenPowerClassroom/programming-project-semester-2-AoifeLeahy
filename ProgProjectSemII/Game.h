// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Globals.h"   // include Global header file
#include "Player.h"   // include Player header file
#include "Enemy.h"   // include Enemy header file


class Game
{
	// private data members

	Player myPlayer;// player object
	static const int MAX_ENEMIES = 2;
	Enemy enemy[MAX_ENEMIES]; // enemy array of 2 that protects the key 

	sf::RenderWindow window;

public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen

public:	  // declaration of member functions	
	Game(); // default constructor
	void loadContent();
	void run();
	void moveEnemies(); // move the enemy objects within the array

private:
	void update();
	void draw();
};
