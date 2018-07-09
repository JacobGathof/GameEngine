#pragma once

#include "AI.h"
#include "World.h"
#include "Keyboard.h"
#include "Mouse.h"

#include "Player.h"

#include "BezierSpline.h"
#include "Line.h"

class PlayerAI : public AI
{
public:
	PlayerAI();
	~PlayerAI();

	Player * user;

	virtual bool execute(Player * obj, float dt);
	virtual void receiveInput(Keyboard& keyboard, Mouse& mouse);

	BezierSpline spline;
	Line line;
	Line line2;
	int numClicks;

protected:
	float xVel;
	float yVel;

	virtual void processInteractKey();
	virtual void processArrowUpKey();
	virtual void leftClick(Vector2f& pos);

};

