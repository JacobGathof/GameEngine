#pragma once

#include "LivingAi.h"
#include "LivingObject.h"
#include "World.h"
#include "Keyboard.h"

class PlayerAI : public LivingAi
{
public:
	PlayerAI();
	~PlayerAI();

	LivingObject * user;

	virtual bool execute(LivingObject * obj, float dt);
	virtual void receiveInput(Keyboard& keyboard);

protected:
	float xVel;
	float yVel;

	virtual void processInteractKey();
	virtual void processArrowUpKey();
};

