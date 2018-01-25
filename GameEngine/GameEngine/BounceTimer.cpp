#include "BounceTimer.h"



BounceTimer::BounceTimer(){}
BounceTimer::~BounceTimer(){}

void BounceTimer::update(float dt)
{
	if (pauseOnTick && tickActive) pause();
	tickActive = false;
	if (paused) return;

	currentTime += dt * timeMultiplier*direction;
	totalTime += dt * timeMultiplier;

	if (currentTime >= tickLength) {
		currentTime = tickLength;
		direction = -1;
		tickActive = true;
	}
	if (currentTime <= 0) {
		currentTime = 0;
		direction = 1;
		tickActive = true;
	}

}