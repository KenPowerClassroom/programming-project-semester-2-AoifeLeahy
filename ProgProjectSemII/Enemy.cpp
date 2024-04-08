// EnemyProtect class 

#include "Enemy.h"   // enemyProtect header file



// enemy function definitions here

Enemy::Enemy()
{
	loadImage(); // loads the image

	imageWidth = 64;

	//initialPosx = (SCREEN_WIDTH / 2) - (imageWidth / 2);

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

void Enemy::moveEnemies(Enemy enemy[], int MAX_ENEMIES)
{
	for (int index = 0; index < MAX_ENEMIES; index++)
	{
		sf::Vector2f pos(sprite.getPosition());

		if (pos.y > 0)
		{
			pos.y --;
		}
		else
		{
			pos.y = SCREEN_HEIGHT - sprite.getGlobalBounds().height;
		}
		
		sprite.setPosition(pos);
	}
	
}

