#include "Game.h"
#include<sstream>
Game::Game(RenderWindow& window) : win(window),isEnterPressed(false),runGame(true),pipeCounter(71),pipeSpawnTime(70),score(0),startMonitoring(false)
{
	win.setFramerateLimit(60);
	background_texture.loadFromFile("assets/bg.png");
	background_sprite.setTexture(background_texture);
	background_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
	background_sprite.setPosition(0.f, -225.f);

	ground_texture.loadFromFile("assets/ground.png");
	ground_sprite1.setTexture(ground_texture);
	ground_sprite2.setTexture(ground_texture);

	ground_sprite1.setScale(SCALE_FACTOR, SCALE_FACTOR);
	ground_sprite2.setScale(SCALE_FACTOR, SCALE_FACTOR);

	ground_sprite1.setPosition(0.f, 578.f);
	ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().width, 578.f);

	font.loadFromFile("assets/arial.ttf");
	restartText.setFont(font);
	restartText.setCharacterSize(50);
	restartText.setFillColor(Color::Black);
	restartText.setPosition(90, 650);
	restartText.setString("Dobaara Aan Deyo!");

	scoreText.setFont(font);
	scoreText.setCharacterSize(30);
	scoreText.setFillColor(Color::Black);
	scoreText.setPosition(15, 15);
	scoreText.setString("Score: 0");



	Pipes::loadPipeTextures();
}
std::string Game::toString(int num)
{
	std::stringstream ss;
	ss << num;
	return ss.str();
}
void Game::draw()
{
	win.draw(background_sprite);
	for (Pipes& pipe : pipes)
	{
		win.draw(pipe.pipeSprite_down);
		win.draw(pipe.pipeSprite_up);
	}
	win.draw(ground_sprite1);
	win.draw(ground_sprite2);
	win.draw(bird.bird_sprite);
	win.draw(scoreText);

	if (runGame == false)
	{
		win.draw(restartText);
	}

}
void Game::moveGround(Time& dt)
{
	ground_sprite1.move(-move_speed * dt.asSeconds(), 0.f);
	ground_sprite2.move(-move_speed * dt.asSeconds(), 0.f);

	if ((ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width) < 0)
	{
		ground_sprite1.setPosition(ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width,578.f);
	}

	if ((ground_sprite2.getGlobalBounds().left + ground_sprite2.getGlobalBounds().width) < 0)
	{
		ground_sprite2.setPosition(ground_sprite1.getGlobalBounds().left + ground_sprite1.getGlobalBounds().width, 578.f);
	}
}

void Game::doProcessing(Time& deltaTime)
{
	if (isEnterPressed == true)
	{
		moveGround(deltaTime);
		if (pipeCounter > pipeSpawnTime)
		{
			pipes.push_back(Pipes(distribution(rd)));
			pipeCounter = 0;
		}
		pipeCounter++;

		for (int i = 0; i < pipes.size(); i++)
		{
			pipes[i].update(deltaTime);
			if (pipes[i].getRightBound() < 0)
			{
				pipes.erase(pipes.begin() + i);
			}

		}
		checkCollisions();
		checkScore();
		
	}
	bird.update(deltaTime);
}

void Game::checkCollisions()
{
	if (pipes.size() > 0)
	{
		if(pipes[0].pipeSprite_down.getGlobalBounds().intersects(bird.bird_sprite.getGlobalBounds()) ||
			pipes[0].pipeSprite_up.getGlobalBounds().intersects(bird.bird_sprite.getGlobalBounds()) ||
			bird.bird_sprite.getGlobalBounds().top >= 540)
		{
			isEnterPressed = false;
			runGame = false;


		}
	}
}

void Game::restartGame()
{
	bird.resetBirdPosition();
	bird.setShouldFly(false);
	runGame = true;
	isEnterPressed = false;
	pipeCounter = 71;
	pipes.clear();
	score = 0;
	scoreText.setString("Score: 0");

}

void Game::checkScore()
{
	if (pipes.size() > 0)
	{
		if (startMonitoring == false)
		{
			if (bird.bird_sprite.getGlobalBounds().left > pipes[0].pipeSprite_down.getGlobalBounds().left && bird.getRightBound() < pipes[0].getRightBound())
			{
				startMonitoring = true;
			}
		}
		else
		{
			if (bird.bird_sprite.getGlobalBounds().left > pipes[0].getRightBound())
			{
				score++;
				scoreText.setString("Score: " + toString(score));
				startMonitoring = false;
				
			}
		}
	}
}

void Game::startGameLoop()
{
	Clock clock;
	// Game-Loop
	while (win.isOpen())
	{
		Time deltaTime = clock.restart();
		Event event;
		//Event-Loop
		while (win.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				win.close();
			}
			if (event.type == Event::KeyPressed && runGame == true)
			{
				if (event.key.code == Keyboard::Enter && isEnterPressed == false)
				{
					isEnterPressed = true;
					bird.setShouldFly(true);

				}
				if (event.key.code == Keyboard::Space && isEnterPressed == true)
				{
					bird.flapBird(deltaTime);
				}

			}
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left && runGame == false)
			{
				if(restartText.getGlobalBounds().contains(event.mouseButton.x,event.mouseButton.y))
				restartGame();
			}
		}
		doProcessing(deltaTime); 
		draw();
		//Display window
		win.display();
	}
}