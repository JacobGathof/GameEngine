#pragma once
#include "ResourceManager.h"
#include "BounceTimer.h"
#include "Text.h"
#include "Screen.h"
#include "GameState.h"
#include "AbstractUIComponent.h"

class StatsPage : public AbstractUIComponent
{
public:
	StatsPage();
	~StatsPage();
	void draw();
	void update(float dt);
	void show();
	void hide();
	virtual void handleMouseEvents(Mouse& mouse);

private:
	Text* text;
	BounceTimer timer;
	Timer textUpdateTimer;
	float transitionTime = 1.0f;

	Vector2f topLeft = Vector2f(10, 790);
	Vector2f botRight = Vector2f(790, 100);

	Vector2f startText = topLeft + Vector2f(6, -6);

};

