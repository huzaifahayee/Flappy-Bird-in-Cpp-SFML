#include "Bird.h"
#include"Globals.h"
Bird::Bird() :gravity(20), flapSpeed(400), animationCounter(0), textureSwtich(1),should_fly(false)
{
	textures[0].loadFromFile("assets/birddown.png");
	textures[1].loadFromFile("assets/birdup.png");

	bird_sprite.setTexture(textures[0]);
	bird_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);

	resetBirdPosition(); 


}

void Bird::setShouldFly(bool should_fly)
{
	this->should_fly = should_fly;
}

void Bird::flapBird(Time& dt)
{
	velocity_y = -flapSpeed * dt.asSeconds(); 
}

void Bird::resetBirdPosition()
{
	bird_sprite.setPosition(100.f, 50.f);
	velocity_y = 0;
}

void Bird::update(Time& dt)
{
	if (bird_sprite.getGlobalBounds().top < 578 && should_fly == true)
	{
		if (animationCounter == 8)
		{
			bird_sprite.setTexture(textures[textureSwtich]);
			if (textureSwtich == 1)
			{
				textureSwtich = 0;
			}
			else
			{
				textureSwtich = 1;
			}
			animationCounter = 0;
		}
		animationCounter++;
		velocity_y += gravity * dt.asSeconds();
		bird_sprite.move(0, velocity_y);

		if (bird_sprite.getGlobalBounds().top < 0)
		{
			bird_sprite.setPosition(100, 0);
		}
	}
}

float Bird::getRightBound()
{
	return bird_sprite.getGlobalBounds().left + bird_sprite.getGlobalBounds().width;
}
