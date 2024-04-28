// EnemyProtect class 

#include "Enemy.h"   // enemyProtect header file

// enemy function definitions here

Enemy::Enemy()
{
	loadImage(); // loads the image

	imageWidth = 64;
	imageHeight = 64;

	speed = 2;
	health = 5;

	initialPosX = 200;
	initialPosY = 100;

	setPosition(initialPosX, initialPosY);
}

void Enemy::loadImage()
{
	if (!upTexture.loadFromFile("ASSETS//IMAGES//enemyProtector_up.png"))
	{
		std::cout << "problem loading protector up image file";
	}
	if (!downTexture.loadFromFile("ASSETS//IMAGES//enemyProtector_down.png"))
	{
		std::cout << "problem loading protector image down file";
	}
	if (!leftTexture.loadFromFile("ASSETS//IMAGES//enemyProtector_left.png"))
	{
		std::cout << "problem loading protector image left file";
	}
	if (!rightTexture.loadFromFile("ASSETS//IMAGES//enemyProtector_right.png"))
	{
		std::cout << "problem loading protector image right file";
	}

	sprite.setTexture(rightTexture);
	sprite.setScale(1.5f, 1.5f);
}

sf::Sprite Enemy::getBody()
{
	return sprite;
}

void Enemy::setPosition()
{
	sprite.setPosition(200, 100);
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

	if (pos.x >= 50 && pos.y == 150 && pos.x < 200) // moves the enemy to the left until a boundary is reached
	{
		pos.x += speed;
		direction = EAST;
		sprite.setTexture(rightTexture);
	}
	else if (pos.y < 300 && pos.y >= 150 && pos.x == 200) // moves the enemy down until a boundary is reached
	{
		direction = SOUTH;
		sprite.setTexture(downTexture);
		pos.y += speed;
	}
	else if (pos.y == 300 && pos.x < 201 && pos.x >= 51) // moves the enemy to the right until a boundary is reached
	{
		direction = WEST;
		sprite.setTexture(leftTexture);
		pos.x -= speed;
	}
	else if (pos.x == 50 && pos.y <= 300 && pos.y > 150) // moves the enemy up until a boundary is reached
	{
		direction = NORTH;
		sprite.setTexture(upTexture);
		pos.y -= speed;
	}
	

	sprite.setPosition(pos.x ,pos.y);
	
}
void Enemy::setAlive(int newAlive)
{
	alive = newAlive;
}

int Enemy::getAlive()
{
	return alive;
}

void Enemy::decreaseLives()
{
	health--;
	if (health <= 0)
	{
		alive = false;
	}
}

void Enemy::reset()
{
	alive = true;
	health = 5;
	sprite.setPosition(200, 100);
}



