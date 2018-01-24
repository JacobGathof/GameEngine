#include "GameTimer.h"



void GameTimer::update()
{
	tickActive = false;
	currentTime = (float)glfwGetTime();
	deltaTime = timeMultiplier*(currentTime - lastTime);
	lastTime = currentTime;


	gameTime += deltaTime;
	frames++;
	if (currentTime - lastTick >= tickLength) {
		lastTick = currentTime;
		tickActive = true;
		fps = frames;
		frames = 0;
	}

}

float GameTimer::getDeltaTime()
{
	return deltaTime;
}

float GameTimer::getGameTime()
{
	return gameTime;
}

void GameTimer::setTimeMult(float f)
{
	timeMultiplier = f;
}

void GameTimer::setTickLength(float f)
{
	tickLength = f;
}

bool GameTimer::tick()
{
	return tickActive;
}

int GameTimer::FPS()
{
	return fps;
}

GameTimer::GameTimer()
{
}


GameTimer::~GameTimer()
{
}
