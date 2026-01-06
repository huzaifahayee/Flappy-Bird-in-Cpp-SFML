#include "Pipes.h"
Pipes::Pipes(int y_pos)
{
	pipeSprite_down.setTexture(pipeTexture_down);
	pipeSprite_up.setTexture(pipeTexture_up);


	pipeSprite_down.setScale(SCALE_FACTOR, SCALE_FACTOR);
	pipeSprite_up.setScale(SCALE_FACTOR, SCALE_FACTOR);

	pipeSprite_up.setPosition(WIN_WIDTH, y_pos);
	pipeSprite_down.setPosition(WIN_WIDTH, y_pos - pipeDistance - pipeSprite_down.getGlobalBounds().height);
}
void Pipes::loadPipeTextures()
{
	pipeTexture_down.loadFromFile("assets/pipedown.png");
	pipeTexture_up.loadFromFile("assets/pipe.png");  


}
void Pipes::update(Time& dt)
{
	pipeSprite_up.move(-pipeMoveSpeed * dt.asSeconds(), 0.f);
	pipeSprite_down.move(-pipeMoveSpeed * dt.asSeconds(), 0.f);
}
float Pipes::getRightBound()
{
	return pipeSprite_down.getGlobalBounds().left + pipeSprite_down.getGlobalBounds().width;
}
Texture Pipes::pipeTexture_down;
Texture Pipes::pipeTexture_up;
int Pipes::pipeDistance = 150;
int Pipes::pipeMoveSpeed = 500;

