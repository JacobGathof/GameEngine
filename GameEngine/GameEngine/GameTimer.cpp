#include "GameTimer.h"
#include <thread>
#include <chrono>
#include <algorithm>
#include <iostream>

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

void GameTimer::setTargetFPS(int f)
{
	targetFPS = f;
}

void GameTimer::sleep()
{
	float f = 1.0f / targetFPS;
	int m = std::max(0, (int)((f - deltaTime) * 1000 * 1000));
	std::this_thread::sleep_for(std::chrono::microseconds(m));
}

GameTimer::GameTimer()
{
}


GameTimer::~GameTimer()
{
}
