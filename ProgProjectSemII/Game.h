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
#include "Bullet.h" // include bullet header file
#include "Rock.h" // include rock header file


class Game
{
	// private data members

	Player myPlayer;// player object

	static const int MAX_ENEMIES = 2;
	Enemy enemies[MAX_ENEMIES]; // enemy array of 2 that protects the key 

	static const int MAX_GUARDS = 4; 
	EnemyGuard enemyGuard[MAX_GUARDS]; // enemy array of 4 that are guards and shoot

	Bullet enemyBullet; // bullet object

	Rock rock; // rock object 

	sf::Texture backgroundTexture; // texture for the background
	sf::Sprite backgroundSprite; // sprite for the background

	sf::RenderWindow window;

	int gameMode; // different modes or screens in the game

public:
	sf::Font m_font;  // font for writing text
	sf::Text m_title;  // text to write on the screen
	sf::Text m_instructions; // the instructions that are written on the screen
	sf::Text m_start;
	sf::Text m_startMessage; // message to start the game


	//the gameplay messages that shows on the screen
	sf::Text healthText;
	sf::Text scoreText;


	// messages at the end of the game
	sf::Text escaped; 
	sf::Text died;
	sf::Text livesLeft;
	sf::Text scoreEnd;
	sf::Text playAgain;
	sf::Text playAgainMessage;
	
	int score = 0; 
	int health = 3;


public:	  // declaration of member functions	
	Game(); // default constructor
	void loadContent();
	void run();
	void initializeArray(); // initializes the array for the first type of enemy (Protectors)
	void initializeArray2();  // initializes the array for the second type of enemy (Guards)
	
	void collisionDetectionEnemy();
	void collisionDetectionPlayer();

	void restartGame();

	void update();
	void draw();
	
	
};
