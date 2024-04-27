// followEnemy class 

#include "FollowEnemy.h"   // followEnemy header file 
#include "Player.h" 

// followEnemy function definitions here

FollowEnemy::FollowEnemy()
{
	loadImage(); // loads the image

	imageWidth = 64;
	imageHeight = 64;

	speed = 1;
	health = 3;

	initialPosX = 800;
	initialPosY = 600;

	setPosition(initialPosX, initialPosY);
}

void FollowEnemy::loadImage()
{
	if (!upTexture.loadFromFile("ASSETS//IMAGES//enemy1_up.png"))
	{
		std::cout << "problem loading follower enemy up image file";
	}
	if (!downTexture.loadFromFile("ASSETS//IMAGES//enemy1_down.png"))
	{
		std::cout << "problem loading follower enemy image down file";
	}
	if (!leftTexture.loadFromFile("ASSETS//IMAGES//enemy1_left.png"))
	{
		std::cout << "problem loading follower enemy image left file";
	}
	if (!rightTexture.loadFromFile("ASSETS//IMAGES//enemy1_right.png"))
	{
		std::cout << "problem loading follower enemy image right file";
	}

	sprite.setTexture(rightTexture);
}

sf::Sprite FollowEnemy::getBody()
{
	return sprite;
}

void FollowEnemy::setPosition()
{
	sprite.setPosition(800, 600);
}

void FollowEnemy::setPosition(int xPos, int yPos)
{
	initialPosX = xPos;
	initialPosY = yPos;
	sprite.setPosition(xPos, yPos);
}

void FollowEnemy::move(Player myPlayer)
{
	sf::Vector2f posEnemy = sprite.getPosition();
	sf::Vector2f posPlayer = myPlayer.getBody().getPosition();

	if (posEnemy.y > posPlayer.y)
	{
		posEnemy.y -= speed;
		sprite.setTexture(upTexture);
	}
	else if (posEnemy.y < posPlayer.y)
	{
		posEnemy.y += speed;
		sprite.setTexture(downTexture);
	}

	if (posEnemy.x < posPlayer.x)
	{
		posEnemy.x += speed;
		sprite.setTexture(rightTexture);
	}
	else if (posEnemy.x > posPlayer.x)
	{
		posEnemy.x -= speed;
		sprite.setTexture(leftTexture);
	}

	sprite.setPosition(posEnemy);
}

void FollowEnemy::setSpeed(int newSpeed)
{
	speed = newSpeed;
}

int FollowEnemy::getSpeed()
{
	speed = 2;
	return speed;
}

void FollowEnemy::setAlive(int newAlive)
{
	alive = newAlive;
}

int FollowEnemy::getAlive()
{
	return alive;
}

void FollowEnemy::decreaseLives()
{
	health--;
	if (health <= 0)
	{
		alive = false;
	}
}

void FollowEnemy::reset()
{
	alive = true;
	health = 3;
	sprite.setPosition(800, 600);
}

