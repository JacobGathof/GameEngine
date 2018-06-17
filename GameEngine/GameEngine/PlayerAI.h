#pragma once

#include "AI.h"
#include "World.h"
#include "Keyboard.h"

#include "Player.h"

class PlayerAI : public AI
{
public:
	PlayerAI();
	~PlayerAI();

	Player * user;

	virtual bool execute(Player * obj, float dt);
	virtual void receiveInput(Keyboard& keyboard);

protected:
	float xVel;
	float yVel;

	virtual void processInteractKey();
	virtual void processArrowUpKey();
};

