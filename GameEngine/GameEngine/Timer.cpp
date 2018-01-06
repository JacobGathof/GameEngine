#include "Timer.h"



void Timer::update()
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

float Timer::getDeltaTime()
{
	return deltaTime;
}

float Timer::getGameTime()
{
	return gameTime;
}

void Timer::setTimeMult(float f)
{
	timeMultiplier = f;
}

void Timer::setTickLength(float f)
{
	tickLength = f;
}

bool Timer::tick()
{
	return tickActive;
}

int Timer::FPS()
{
	return fps;
}

Timer::Timer()
{
}


Timer::~Timer()
{
}
