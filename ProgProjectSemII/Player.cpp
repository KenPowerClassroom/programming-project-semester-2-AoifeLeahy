// Player class 

#include "Player.h"   // include Player header file


// Player function definitions here

Player::Player() // default constructor
{
	loadImage(); 

	imageWidth = 64;
	imageHeight = 64;

	int xPos = 700;
	int yPos = 280;

	speed = 4; 
	direction = WEST;
	health = 5;

	setPosition(xPos, yPos); // sets position of the player
}

void Player::loadImage()
{
	if (!upTexture.loadFromFile("ASSETS//IMAGES//player_up.png"))
	{
		std::cout << "problem loading player up image file";
	}
	if (!downTexture.loadFromFile("ASSETS//IMAGES//player_down.png"))
	{
		std::cout << "problem loading player image down file";
	}
	if (!leftTexture.loadFromFile("ASSETS//IMAGES//player_left.png"))
	{
		std::cout << "problem loading player image left file";
	}
	if (!rightTexture.loadFromFile("ASSETS//IMAGES//player_right.png"))
	{
		std::cout << "problem loading player image right file";
	}

	sprite.setTexture(leftTexture);
}

sf::Sprite Player::getBody()
{
	return sprite;
}

void Player::setPosition()
{
	sprite.setPosition(700, 280);
}

sf::Vector2f Player::getPosition()
{
	sf::Vector2f playerPos = sprite.getPosition();
	return playerPos;
}

void Player::setPosition(int xPos, int yPos)
{
	sprite.setPosition(xPos, yPos);
}

void Player::moveDown()
{
	sf::Vector2f pos(sprite.getPosition());

	if (pos.y >= SCREEN_HEIGHT - imageHeight)
	{
		pos.y = SCREEN_HEIGHT - imageHeight;
	}
	else
	{
		pos.y+= speed;
	}
	
	sprite.setPosition(pos);
	sprite.setTexture(downTexture);
	direction = SOUTH;
}

void Player::moveUp()
{
	sf::Vector2f pos(sprite.getPosition());

	if (pos.y < 0)
	{
		pos.y = 0;
	}
	else
	{
		pos.y-= speed;
	}

	sprite.setPosition(pos);
	sprite.setTexture(upTexture); 
	direction = NORTH;
}


void Player::moveRight()
{
	sf::Vector2f pos(sprite.getPosition());

	pos.x+= speed;

	if (pos.x >= SCREEN_WIDTH - imageWidth)
	{
		pos.x = SCREEN_WIDTH - imageWidth;
	}
	

	sprite.setPosition(pos);
	sprite.setTexture(rightTexture);
	direction = EAST;
}

void Player::moveLeft()
{
	sf::Vector2f pos(sprite.getPosition());

	pos.x-= speed;

	if (pos.x <= 0)
	{
		pos.x = 0;
	}

	sprite.setPosition(pos);
	sprite.setTexture(leftTexture);
	direction = WEST;
}

int Player::getDirection()
{
	return direction;
}

void Player::setAlive(int newAlive)
{
	alive = newAlive;
}

int Player::getAlive()
{
	return alive;
}

void Player::decreaseLives()
{
	health--;
	if (health <= 0)
	{
		alive = false;
	}
	sprite.setPosition(700, 280);
}

void Player::reset()
{
	alive = true;
	health = 5;
	direction = WEST;
	sprite.setPosition(700, 280);
}