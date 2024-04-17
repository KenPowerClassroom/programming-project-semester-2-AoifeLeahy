// Game class declaration
#pragma once

#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function

#include "Globals.h"   // include Global header file
#include "Player.h"   // include Player header file
#include "Enemy.h"   // include Enemy header file
#include "EnemyGuard.h" // include EnemyGuard header file 


class Game
{
	// private data members

	Player myPlayer;// player object
	static const int MAX_ENEMIES = 2;
	Enemy enemies[MAX_ENEMIES]; // enemy array of 2 that protects the key 

	static const int MAX_GUARDS = 4; 
	EnemyGuard enemyGuard[MAX_GUARDS]; // enemy array of 4 that are guards and shoot


	sf::Texture backgroundTexture; // texture for the background
	sf::Sprite backgroundSprite; // sprite for the background

	sf::RenderWindow window;

public:
	sf::Font m_font;  // font for writing text
	sf::Text m_message;  // text to write on the screen

public:	  // declaration of member functions	
	Game(); // default constructor
	void loadContent();
	void run();
	void initializeArray(); // initializes the array for the first type of enemy (Protectors)
	void initializeArray2();  // initializes the array for the second type of enemy (Guards)

private:
	void update();
	void draw();

	
};
