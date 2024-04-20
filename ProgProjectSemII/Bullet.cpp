// Bullet class 

#include "Bullet.h"   // bullet header file

// bullet function definitions here

Bullet::Bullet()
{
	loadImage(); // loads this function to load image files
}

void Bullet::loadImage()
{
	/*if (!bulletTexture.loadFromFile("ASSETS\\IMAGES\\fireball_right.png"))
	{
		std::cout << "problem loading bullet" << std::endl;
	}

	sprite.setTexture(bulletTexture);*/
}

sf::Sprite Bullet::getBody()
{
	return sprite;
}

void Bullet::setPosition()
{
	sprite.setPosition(200, 200);
}

void Bullet::setPosition(int xPos, int yPos)
{
	sprite.setPosition(xPos, yPos);
}

