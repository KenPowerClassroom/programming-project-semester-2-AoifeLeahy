// Rock class

#include "Rock.h"   // Rock header file
#include "Player.h"


// Rock function definitions here

Rock::Rock() // default constructor
{
	loadImage();
	
	speed = 7;
	direction = WEST;

}

void Rock::loadImage()
{
	if (!texture.loadFromFile("ASSETS\\IMAGES\\fireball_left.png"))
	{
		std::cout << "problem loading rock" << std::endl;
	}
	sprite.setTexture(texture);
}

sf::Sprite Rock::getBody()
{
	return sprite;
}

void Rock::fired(Player myPlayer)
{
	isFired = true;
	direction = myPlayer.getDirection();
	sf::Vector2f playerPos = myPlayer.getPosition();
	sprite.setPosition(playerPos);
	isActive = true;

}

void Rock::move()
{
	sf::Vector2f pos(sprite.getPosition());

	if (direction == NORTH)
	{
		pos.y -= speed;
		sprite.setTexture(texture);
	}
	if (direction == SOUTH)
	{
		pos.y += speed;
		sprite.setTexture(texture);
	}
	if (direction == EAST)
	{
		pos.x += speed;
		sprite.setTexture(texture);
	}
	if (direction == WEST)
	{
		pos.x -= speed;
		sprite.setTexture(texture);
	}
	sprite.setPosition(pos);
}














