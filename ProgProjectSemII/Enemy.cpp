// EnemyProtect class 

#include "Enemy.h"   // enemyProtect header file



// enemy function definitions here

Enemy::Enemy()
{
	loadImage(); // loads the image

	imageWidth = 64;
	imageHeight = 64;


	setPosition(100, 400); // this sets the position for the enemy


}

void Enemy::loadImage()
{
	if (!texture.loadFromFile("ASSETS//IMAGES//enemy1_right.png"))
	{
		std::cout << "problem with loading the enemy file";
	}

	sprite.setTexture(texture);
}

sf::Sprite Enemy::getBody()
{
	return sprite;
}

void Enemy::setPosition()
{
	sprite.setPosition(100, 400);
}

void Enemy::setPosition(int xPos, int yPos)
{
	sprite.setPosition(xPos, yPos);
}

void Enemy::moveEnemies()
{
	sf::Vector2f pos(sprite.getPosition());

	if (direction == NORTH)
	{
		pos.y -= speed;
	}
	else if (direction == SOUTH)
	{
		pos.y += speed;
	}
	if (pos.y <= 0)
	{
		direction = SOUTH;
	}
	else if (pos.y >= SCREEN_WIDTH - imageHeight)
	{
		direction = NORTH;
	}

	sprite.setPosition(pos);
	
}


