// Player class 

#include "Player.h"   // include Player header file


// Player function definitions here

Player::Player() // default constructor
{
	loadImage(); 

	int xPos = 1400;
	int yPos = 380;
	setPosition(xPos, yPos); // sets position of the player
}

void Player::loadImage()
{
	if (!texture.loadFromFile("ASSETS//IMAGES//player_left.png"))
	{
		std::cout << "problem loading player image file";
	}

	sprite.setTexture(texture);
}

sf::Sprite Player::getBody()
{
	return sprite;
}

void Player::setPosition()
{
	sprite.setPosition(200, 200);
}

void Player::setPosition(int xPos, int yPos)
{
	sprite.setPosition(xPos, yPos);
}

void Player::moveLeft()
{
	sf::Vector2f pos(sprite.getPosition());

	if (pos.x >= SCREEN_WIDTH)
	{
		pos.x = -0.0f;
	}
	else
	{
		pos.x--;
	}
	

	sprite.setPosition(pos);
}

void Player::moveRight()
{
	sf::Vector2f pos(sprite.getPosition());

	if (pos.x >= SCREEN_WIDTH)
	{
		pos.x = -0.0f;
	}
	else
	{
		pos.x++;
	}
	
	sprite.setPosition(pos);

}

void Player::moveDown()
{
	sf::Vector2f pos(sprite.getPosition());

	if (pos.y >= SCREEN_HEIGHT)
	{
		pos.y = -0.0f;
	}
	else
	{
		pos.y++;
	}
	

	sprite.setPosition(pos);
}

void Player::moveUp()
{
	sf::Vector2f pos(sprite.getPosition());

	if (pos.y >= SCREEN_HEIGHT)
	{
		pos.y = -0.0f;
	}
	else
	{
		pos.y--;
	}

	sprite.setPosition(pos);
}