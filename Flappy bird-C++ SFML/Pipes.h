#pragma once
#include<SFML/Graphics.hpp>
#include"Globals.h"
using namespace sf;
class Pipes
{
private:
	static Texture pipeTexture_down;
	static Texture pipeTexture_up;

	static int pipeDistance;
	static int pipeMoveSpeed;
public:
	Pipes(int);
	Sprite pipeSprite_up;
	Sprite pipeSprite_down;
	static void loadPipeTextures();
	void update(Time&);
	float getRightBound();

};

