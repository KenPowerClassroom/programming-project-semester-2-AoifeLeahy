//EnemyGuard class

#include "EnemyGuard.h"   // enemyProtect header file

// enemy function definitions here

EnemyGuard::EnemyGuard()
{
	loadImage(); // loads the image 

	imageWidth = 64;
	imageHeight = 64;

	speed = 4;
	direction = NORTH;
	health = 5;

	initialPosX = 400;
	initialPosY = 600;

	setPosition(initialPosX, initialPosY); // this sets the position for the enemy

}

void EnemyGuard::loadImage()
{
	if (!upTexture.loadFromFile("ASSETS//IMAGES//enemy2_up.png"))
	{
		std::cout << "problem loading player up image file";
	}
	if (!downTexture.loadFromFile("ASSETS//IMAGES//enemy2_down.png"))
	{
		std::cout << "problem loading player image down file";
	}
	if (!leftTexture.loadFromFile("ASSETS//IMAGES//enemy2_left.png"))
	{
		std::cout << "problem loading player image left file";
	}
	if (!rightTexture.loadFromFile("ASSETS//IMAGES//enemy2_right.png"))
	{
		std::cout << "problem loading player image right file";
	}

	sprite.setTexture(rightTexture);
}

sf::Sprite EnemyGuard::getBody()
{
	return sprite; 
}

void EnemyGuard::setPosition()
{
	sprite.setPosition(500, 400);
}

void EnemyGuard::setPosition(int xPos, int yPos)
{
	initialPosX = xPos;
	initialPosY = yPos;
	sprite.setPosition(xPos, yPos);
}

sf::Vector2f EnemyGuard::getPosition()
{
	sf::Vector2f enemyPos = sprite.getPosition();
	return enemyPos;
}

int EnemyGuard::getDirection()
{
	return direction;
}

void EnemyGuard::moveEnemyGuard()
{
	sf::Vector2f pos(sprite.getPosition());

	int maxDistance = 50;

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
		movingDown = !movingDown;
	}
	if (movingDown)
	{
		pos.y += 1;
	}
	else
	{
		pos.y -= 1;
	}
	sprite.setPosition(pos);

}

void EnemyGuard::setAlive(int newAlive)
{
	alive = newAlive;
}

int EnemyGuard::getAlive()
{
	return alive;
}

void EnemyGuard::decreaseLives()
{
	health--;
	if (health <= 0)
	{
		alive = false;
	}
}

void EnemyGuard::reset()
{
	alive = true;
	health = 5;
}