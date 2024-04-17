// EnemyProtect class 

#include "Enemy.h"   // enemyProtect header file

// enemy function definitions here

Enemy::Enemy()
{
	loadImage(); // loads the image

	imageWidth = 64;
	imageHeight = 64;

	speed = 2;
	direction = NORTH;

	initialPosX = 200;
	initialPosY = 400;

	setPosition(initialPosX, initialPosY);
}

void Enemy::loadImage()
{
	if (!upTexture.loadFromFile("ASSETS//IMAGES//enemy1_up.png"))
	{
		std::cout << "problem loading player up image file";
	}
	if (!downTexture.loadFromFile("ASSETS//IMAGES//enemy1_down.png"))
	{
		std::cout << "problem loading player image down file";
	}
	if (!leftTexture.loadFromFile("ASSETS//IMAGES//enemy1_left.png"))
	{
		std::cout << "problem loading player image left file";
	}
	if (!rightTexture.loadFromFile("ASSETS//IMAGES//enemy1_right.png"))
	{
		std::cout << "problem loading player image right file";
	}

	sprite.setTexture(rightTexture);
}

sf::Sprite Enemy::getBody()
{
	return sprite;
}

void Enemy::setPosition()
{
	sprite.setPosition(200, 400);
}

void Enemy::setPosition(int xPos, int yPos)
{
	initialPosX = xPos;
	initialPosY = yPos; 
	sprite.setPosition(xPos, yPos);
}

void Enemy::moveEnemies()
{
	sf::Vector2f pos(sprite.getPosition());

	int maxDistance = 30; 

	if (pos.x <= initialPosX - maxDistance || pos.x >= initialPosX + maxDistance)
	{
		movingRight = !movingRight;
	}
	if (movingRight)
	{
		pos.x += speed;
	}
	else
	{
		pos.x -= speed;
	}
	if (pos.y <= initialPosY - maxDistance || pos.y >= initialPosY + maxDistance)
	{
		movingUp = !movingUp;
	}
	if (movingUp)
	{
		pos.y -= 1;
	}
	else
	{
		pos.y += 1;
	}
	sprite.setPosition(pos);
	
}


