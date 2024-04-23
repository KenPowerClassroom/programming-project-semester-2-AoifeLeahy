// Name: 
// Login: 
// Date: 
// Approximate time taken: 
//---------------------------------------------------------------------------
// Project description: TEMPLATE
// ---------------------------------------------------------------------------
// Known Bugs:
// ?

//////////////////////////////////////////////////////////// 
// include correct library file for release and debug versions
//////////////////////////////////////////////////////////// 

#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib")




#include "Game.h"   // include Game header file



int main()
{
	Game aGame;
	aGame.loadContent();
	aGame.run();

	return 0;
}

Game::Game() : window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default)
// Default constructor
{
	initializeArray();
	initializeArray2();
}

void Game::loadContent()
// Load the font file & setup the message string
{

	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	
	
	if (!backgroundTexture.loadFromFile("ASSETS\\IMAGES\\floor.png"))
	{
		std::cout << "problem loading the background" << std::endl;
	}
	backgroundSprite.setTexture(backgroundTexture); // sets texture for the background


}


void Game::run()
// This function contains the main game loop which controls the game. 
{

	srand((int)time(nullptr)); // set the seed once

	sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);

	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// the clock object keeps the time.
	sf::Clock clock;


	clock.restart();

	while (window.isOpen())
	{
		// check if the close window button is clicked on
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//get the time since last update and restart the clock
		timeSinceLastUpdate += clock.restart();

		//update every 60th of a second
		//only when the time since last update is greater than 1/60 update the world.
		if (timeSinceLastUpdate > timePerFrame)
		{
			update();
			draw();

			// reset the timeSinceLastUpdate to 0 
			timeSinceLastUpdate = sf::Time::Zero;
		}
	}  // end while loop

}


void Game::initializeArray()
{
	enemies[0].setPosition(50, 150);
	enemies[1].setPosition(200, 150);
}

void Game::initializeArray2()
{
	enemyGuard[0].setPosition(320, 120);
	enemyGuard[1].setPosition(320, 220);
	enemyGuard[2].setPosition(320, 320);
	enemyGuard[3].setPosition(320, 420);
}

void Game::update()
// This function takes the keyboard input and updates the game world
{
	// get keyboard input
	if (myPlayer.getAlive())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			rock.fired(myPlayer);
		}
		rock.move();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		myPlayer.moveLeft();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		myPlayer.moveRight(); 
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		myPlayer.moveDown();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		myPlayer.moveUp();
	}
	// update any game variables here ...
	for (int index = 0; index < MAX_ENEMIES; index++)
	{
		enemies[index].moveEnemies(); // call the function to move the enemy objects
	}
	for (int index = 0; index < MAX_GUARDS; index++)
	{
		enemyGuard[index].moveEnemyGuard(); // calls the function to move the enemy guard objects
	}
	collisionDetectionEnemy();
	collisionDetectionPlayer();
}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();

	window.draw(backgroundSprite);

	if (myPlayer.getAlive())
	{
		window.draw(myPlayer.getBody()); // this draws the player object 
	}
	//window.draw(enemyBullet.getBody()); // this draws the bullet object

	if (rock.isActive)
	{
		window.draw(rock.getBody());
	}
	
	for (int index = 0; index < MAX_ENEMIES; index++)
	{
		if (enemies[index].getAlive())
		{
			window.draw(enemies[index].getBody()); // this draws the enemy protector object
		}
	}

	for (int index = 0; index < MAX_GUARDS; index++)
	{
		if (enemyGuard[index].getAlive())
		{
			window.draw(enemyGuard[index].getBody()); // this draws the enemy guard object
		}
	}

	
	window.display();
}

void Game::collisionDetectionEnemy()
{
	sf::FloatRect enemyGuardRec;
	sf::FloatRect rockRec;
	sf::FloatRect enemyProtectorRec;

	if (rock.isActive)
	{
		rockRec = rock.getBody().getGlobalBounds();

		for (int count = 0; count < MAX_GUARDS; count++)
		{
			enemyGuardRec = enemyGuard[count].getBody().getGlobalBounds();
			if (enemyGuard[count].getAlive())
			{
				if (rockRec.intersects(enemyGuardRec))
				{
					enemyGuard[count].decreaseLives();
					rock.reset(myPlayer);
					score = score + 2;
					scoreText.setString("Score: " + std::to_string(score));
				}
			}
		}
		for (int count = 0; count < MAX_ENEMIES; count++)
		{
			enemyProtectorRec = enemies[count].getBody().getGlobalBounds();
			if (enemies[count].getAlive())
			{
				if (rockRec.intersects(enemyProtectorRec))
				{
					enemies[count].decreaseLives();
					rock.reset(myPlayer);
					score = score + 2;
					scoreText.setString("Score: " + std::to_string(score));
				}
			}
		}
	}
}

void Game::collisionDetectionPlayer()
{
	sf::FloatRect enemyGuardRec;
	sf::FloatRect playerRec;
	sf::FloatRect enemyProtectorRec;
	sf::FloatRect rockRec;

	playerRec = myPlayer.getBody().getGlobalBounds();

	for (int count = 0; count < MAX_GUARDS; count++)
	{
		enemyGuardRec = enemyGuard[count].getBody().getGlobalBounds();
		if (enemyGuard[count].getAlive())
		{
			if (playerRec.intersects(enemyGuardRec))
			{
				myPlayer.decreaseLives();
				health--;
			}
		}
	}
	for (int count = 0; count < MAX_ENEMIES; count++)
	{
		enemyProtectorRec = enemies[count].getBody().getGlobalBounds();
		if (enemies[count].getAlive())
		{
			if (playerRec.intersects(enemyProtectorRec))
			{
				myPlayer.decreaseLives();
				health--;
			}
			
		}
	}
}



void Game::restartGame()
{
	/*myPlayer.reset();
	for (int count = 0; count < MAX_ENEMIES; count++)
	{
		enemies[count].reset();
	}
	for (int count = 0; count < MAX_GUARDS; count++)
	{
		enemyGuard[count].reset();
	}
	int posX = (SCREEN_WIDTH / 2) - (64 / 2);
	int posY = 61;
	initializeArray();
	initializeArray2();
	health = 5;
	score = 0; */
	

}

