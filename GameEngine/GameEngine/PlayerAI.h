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
	void receiveInput(Keyboard& keyboard);

private:
	float xVel;
	float yVel;
};

