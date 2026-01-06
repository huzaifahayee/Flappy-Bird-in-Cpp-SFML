#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include"Globals.h"
#include"Bird.h"
#include"Pipes.h"
#include<random>
using namespace sf;
using namespace std;
class Game
{
private:
	Bird bird;

	Texture background_texture;
	Texture ground_texture;
	Sprite background_sprite;
	Sprite ground_sprite1;
	Sprite ground_sprite2;



	int move_speed = 280;
	int pipeCounter;
	int pipeSpawnTime;
	int score;
	bool isEnterPressed;
	bool runGame;
	bool startMonitoring;

	vector<Pipes> pipes;
	random_device rd;
	uniform_int_distribution<int> distribution{ 250,550 };

	std::string toString(int);

	Font font;
	Text restartText;
	Text scoreText;


	void draw();
	void moveGround(Time& dt);
	void doProcessing(Time& dt);
	void checkCollisions();
	void restartGame();
	void checkScore();
public:
	Game(RenderWindow &window);
	RenderWindow& win;
	void startGameLoop();
		
};

