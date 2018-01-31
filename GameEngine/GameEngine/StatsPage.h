#pragma once
#include "ResourceManager.h"
#include "BounceTimer.h"
#include "Text.h"
#include "Screen.h"
#include "GameState.h"

class StatsPage
{
public:
	StatsPage();
	~StatsPage();
	void draw();
	void update(float dt);
	void show();
	void hide();

private:
	Text text;
	BounceTimer timer;
	Timer textUpdateTimer;
	Vector2f position;
	float transitionTime = 1.0f;

	Vector2f topLeft = Vector2f(10, 790);
	Vector2f botRight = Vector2f(790, 100);

	Vector2f startText = topLeft + Vector2f(6, -6);

};

