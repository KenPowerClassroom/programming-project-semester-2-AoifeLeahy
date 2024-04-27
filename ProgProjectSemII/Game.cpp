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
	gameMode = main_screen;
}

void Game::loadContent()
// Load the font file & setup the message string
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	if (!backgroundTexture.loadFromFile("ASSETS\\IMAGES\\background temp.png"))
	{
		std::cout << "problem loading the background" << std::endl;
	}
	backgroundSprite.setTexture(backgroundTexture); // sets texture for the background

	if (!keyTexture.loadFromFile("ASSETS\\IMAGES\\key.png"))
	{
		std::cout << "problem loading key" << std::endl;
	}
	keySprite.setTexture(keyTexture);
	keySprite.setPosition(130, 240);

	if (!m_backgroundBuffer.loadFromFile("ASSETS\\AUDIO\\background music.wav"))
	{
		std::cout << "problem loading background music" << std::endl;
	}
	m_backgroundMusic.setBuffer(m_backgroundBuffer);

	if (gameMode == main_screen)
	{
		m_backgroundMusic.play();
		m_backgroundMusic.setLoop(true);
	}
	else if (gameMode == game_Play)
	{
		m_backgroundMusic.play();
		m_backgroundMusic.setLoop(true);
	}

	if (!m_damageBuffer.loadFromFile("ASSETS\\AUDIO\\damage.wav"))
	{
		std::cout << "problem loading damage sound" << std::endl;
	}
	m_damageSound.setBuffer(m_damageBuffer);

	if (!m_gameOverBuffer.loadFromFile("ASSETS\\AUDIO\\gameOver.wav"))
	{
		std::cout << "problem loading game over sound" << std::endl;
	}
	m_gameOver.setBuffer(m_gameOverBuffer);
	
	if (!m_throwBuffer.loadFromFile("ASSETS\\AUDIO\\throwing_rock.wav"))
	{
		std::cout << "problem loading throwing sound" << std::endl;
	}
	m_throwRock.setBuffer(m_throwBuffer);

	if (!m_enemyHitBuffer.loadFromFile("ASSETS\\AUDIO\\enemy_hit.wav"))
	{
		std::cout << "problem loading enemy hitting sound" << std::endl;
	}
	m_enemyHit.setBuffer(m_enemyHitBuffer);

	m_title.setPosition(200,30);
	m_title.setFont(m_font);
	m_title.setFillColor(sf::Color::White);
	m_title.setOutlineColor(sf::Color::Blue);
	m_title.setOutlineThickness(5);
	m_title.setCharacterSize(50);

	m_instructions.setPosition(200, 120);
	m_instructions.setFont(m_font);
	m_instructions.setFillColor(sf::Color::White);
	m_instructions.setCharacterSize(20);

	m_start.setPosition(200, 400);
	m_start.setFont(m_font);
	m_start.setFillColor(sf::Color::White);
	m_start.setOutlineColor(sf::Color::Red);
	m_start.setOutlineThickness(5);
	m_start.setCharacterSize(100);

	m_startMessage.setPosition(230, 530);
	m_startMessage.setFont(m_font);
	m_startMessage.setFillColor(sf::Color::White);
	m_startMessage.setCharacterSize(15);

	escaped.setPosition(260, 100);
	escaped.setFont(m_font);
	escaped.setFillColor(sf::Color::White);
	escaped.setOutlineColor(sf::Color::Blue);
	escaped.setOutlineThickness(5);
	escaped.setCharacterSize(65);

	died.setPosition(220, 100);
	died.setFont(m_font);
	died.setFillColor(sf::Color::White);
	died.setOutlineColor(sf::Color::Blue);
	died.setOutlineThickness(5);
	died.setCharacterSize(80);

	scoreEnd.setPosition(300, 300);
	scoreEnd.setFont(m_font);
	scoreEnd.setFillColor(sf::Color::White);
	scoreEnd.setCharacterSize(40);

	livesLeft.setPosition(300, 220);
	livesLeft.setFont(m_font);
	livesLeft.setFillColor(sf::Color::White);
	livesLeft.setCharacterSize(35);

	playAgain.setPosition(260, 400);
	playAgain.setFont(m_font);
	playAgain.setFillColor(sf::Color::White);
	playAgain.setOutlineColor(sf::Color::Red);
	playAgain.setOutlineThickness(5);
	playAgain.setCharacterSize(50);

	playAgainMessage.setPosition(230, 560);
	playAgainMessage.setFont(m_font);
	playAgainMessage.setFillColor(sf::Color::White);
	playAgainMessage.setCharacterSize(15);

	scoreText.setPosition(650, 570);
	scoreText.setFont(m_font);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setCharacterSize(20);

	healthText.setPosition(40, 570);
	healthText.setFont(m_font);
	healthText.setFillColor(sf::Color::White);
	healthText.setCharacterSize(20);
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
	enemies[2].setPosition(200, 300);
}

void Game::initializeArray2()
{
	enemyGuard[0].setPosition(330, 100);
	enemyGuard[1].setPosition(330, 220);
	enemyGuard[2].setPosition(330, 340);
	enemyGuard[3].setPosition(330, 460);
}

void Game::update()
// This function takes the keyboard input and updates the game world
{
	// get keyboard input

	if (gameMode == main_screen)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			gameMode = game_Play;
		}
	}
	else if (gameMode == game_Play)
	{
		collisionDetectionEnemy();
		collisionDetectionPlayer();


		if (myPlayer.getAlive())
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				rock.fired(myPlayer);
				m_throwRock.play();
			}
			rock.move();
		}
		if (myPlayer.getAlive() == false)
		{
			gameMode = game_over;
			m_backgroundMusic.stop();
			m_gameOver.play();
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
			if (enemies[index].getAlive())
			{
				enemies[index].moveEnemies(); // call the function to move the enemy objects
			}
			
		}
		for (int index = 0; index < MAX_GUARDS; index++)
		{
			enemyGuard[index].moveEnemyGuard(); // calls the function to move the enemy guard objects
		}

		if (follower.getAlive())
		{
			follower.move(myPlayer);
		}
		if (follower.getAlive() == false)
		{
			follower.reset();
		}
	}
	else if (gameMode == game_win)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		{
			gameMode = game_Play;
			restartGame();
		}
	}
	else if (gameMode == game_over)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace))
		{
			gameMode = game_Play;
			restartGame();
			
		}
	}
	
}

void Game::draw()
// This function draws the game world
{
	// Clear the screen and draw your game sprites
	window.clear();

	
	if (gameMode == main_screen)
	{
		m_title.setString("INSTRUCTIONS: ");
		m_instructions.setString("1. Avoid the guards! \n\n2. Avoid security! \n\n3. Avoid bullets! \n\n4. Secure the key to escape. \n\n5.Use <ARROW KEYS> to move player. \n\n6.Use <SPACE> to shoot.");
		m_start.setString("START");
		m_startMessage.setString("Press <ENTER> to start");
		window.draw(m_title);
		window.draw(m_instructions);
		window.draw(m_start);
		window.draw(m_startMessage);
	}
	else if (gameMode == game_Play)
	{
		window.draw(backgroundSprite);
		scoreText.setString("Score: " + std::to_string(score));
		healthText.setString("Lives: " + std::to_string(health));
		window.draw(scoreText);
		window.draw(healthText);
		window.draw(keySprite);

		if (myPlayer.getAlive())
		{
			window.draw(myPlayer.getBody()); // this draws the player object 
		}

		if (rock.isActive)
		{
			window.draw(rock.getBody());
		}

		if (follower.getAlive())
		{
			window.draw(follower.getBody());
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
	
	}
	else if (gameMode == game_win)
	{
		escaped.setString("YOU WON!");
		window.draw(escaped);
		scoreEnd.setString("Score: " + std::to_string(score));
		window.draw(scoreEnd);
		livesLeft.setString("Lives left: " + std::to_string(health));
		window.draw(livesLeft);
		playAgain.setString("Play Again? ");
		window.draw(playAgain);
	}
	else if (gameMode == game_over)
	{
		died.setString("GAME OVER");
		window.draw(died);
		scoreEnd.setString("Score: " + std::to_string(score));
		window.draw(scoreEnd);
		playAgain.setString("Play Again? ");
		window.draw(playAgain);

	}
	

	//window.draw(enemyBullet.getBody()); // this draws the bullet object

	
	window.display();
}

void Game::collisionDetectionEnemy()
{
	sf::FloatRect enemyGuardRec;
	sf::FloatRect rockRec;
	sf::FloatRect enemyProtectorRec;
	sf::FloatRect followEnemyRec;

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
					m_enemyHit.play();
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
					m_enemyHit.play();
				}
			}
		}

		if (follower.getAlive())
		{
			followEnemyRec = follower.getBody().getGlobalBounds();
			if (rockRec.intersects(followEnemyRec))
			{
				follower.decreaseLives();
				follower.setPosition(800, 600);
				rock.reset(myPlayer);
				score = score + 2;
				scoreText.setString("Score: " + std::to_string(score));
				m_enemyHit.play();
			}
		}
	}
}

void Game::collisionDetectionPlayer()
{
	sf::FloatRect enemyGuardRec;
	sf::FloatRect playerRec;
	sf::FloatRect enemyProtectorRec;
	sf::FloatRect followEnemyRec;
	sf::FloatRect rockRec;
	sf::FloatRect keyRec;

	playerRec = myPlayer.getBody().getGlobalBounds();
	keyRec = keySprite.getGlobalBounds();

	if (playerRec.intersects(keyRec))
	{
		gameMode = game_win;
	}

	for (int count = 0; count < MAX_GUARDS; count++)
	{
		enemyGuardRec = enemyGuard[count].getBody().getGlobalBounds();
		if (enemyGuard[count].getAlive())
		{
			if (playerRec.intersects(enemyGuardRec))
			{
				myPlayer.decreaseLives();
				health--;
				m_damageSound.play();
		
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
				m_damageSound.play();
			}
			
		}
	}

	if (follower.getAlive())
	{
		followEnemyRec = follower.getBody().getGlobalBounds();
		if (playerRec.intersects(followEnemyRec))
		{
			myPlayer.decreaseLives();
			health--;
			follower.setPosition(800, 600);
			m_damageSound.play();
		}
	}


}



void Game::restartGame()
{
	myPlayer.reset();
	for (int count = 0; count < MAX_ENEMIES; count++)
	{
		enemies[count].reset();
	}
	for (int count = 0; count < MAX_GUARDS; count++)
	{
		enemyGuard[count].reset();
	}
	follower.reset();
	initializeArray();
	initializeArray2();
	health = 5;
	score = 0; 
	m_backgroundMusic.play();
	

}

