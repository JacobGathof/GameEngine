#include "Timer.h"



Timer::Timer(){}
Timer::~Timer(){}

void Timer::update(float dt)
{
	if (pauseOnTick && tickActive) pause();
	tickActive = false;
	if (paused) return;

	currentTime += dt * timeMultiplier;
	totalTime += dt * timeMultiplier;

	if (currentTime >= tickLength) {
		currentTime = 0;
		tickActive = true;
	}

}

void Timer::setTimeMult(float f)
{
	timeMultiplier = f;
}

void Timer::setTickLength(float f)
{
	tickLength = f;
}

bool Timer::tick(){
	return tickActive;
}

void Timer::pause(){
	paused = true;
}

void Timer::unpause(){
	paused = false;
}

bool Timer::isPaused()
{
	return paused;
}

void Timer::setPauseOnTick(bool pot)
{
	pauseOnTick = pot;
}

void Timer::reset()
{
	currentTime = 0.0;
	totalTime = 0.0f;
}

float Timer::getTotalTime()
{
	return totalTime;
}

float Timer::getCurrentTime()
{
	return currentTime;
}

