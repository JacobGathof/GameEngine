#pragma once
#include "glfw3.h"

class GameTimer
{
public:
	void update();
	float getDeltaTime();
	float getGameTime();
	void setTimeMult(float f);
	void setTickLength(float f);
	bool tick();
	int FPS();

	void setTargetFPS(int f);
	void sleep();

	GameTimer();
	~GameTimer();
private:
	float deltaTime = 0.0f;
	float currentTime = 0.0f;
	float lastTime = 0.0f;
	float gameTime = 0.0f;
	float timeMultiplier = 1.0f;
	float lastTick = 0.0f;

	float tickLength = 1.0f;

	int frames = 0;
	int fps = 0;
	bool tickActive = false;

	int targetFPS = 60;
};

