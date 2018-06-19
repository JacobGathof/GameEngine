#pragma once

#include "AI.h"
#include "World.h"
#include "Keyboard.h"
#include "Mouse.h"

#include "Player.h"

class PlayerAI : public AI
{
public:
	PlayerAI();
	~PlayerAI();

	Player * user;

	virtual bool execute(Player * obj, float dt);
	virtual void receiveInput(Keyboard& keyboard, Mouse& mouse);

protected:
	float xVel;
	float yVel;

	virtual void processInteractKey();
	virtual void processArrowUpKey();
	virtual void leftClick(Vector2f& pos);
};

