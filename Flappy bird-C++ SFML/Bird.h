#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class Bird
{
private:
	Texture textures[2];
	const int gravity;
	const int flapSpeed;
	float velocity_y;
	int animationCounter;
	int textureSwtich;
	bool should_fly;
public:
	Sprite bird_sprite;
	Bird();
	void setShouldFly(bool);
	void flapBird(Time&);
	void resetBirdPosition();
	void update(Time&);
	float getRightBound();

};

