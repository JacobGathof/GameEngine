#pragma once

#include "LivingAi.h"
#include "Input.h"
#include "LivingObject.h"
#include "World.h"

class PlayerAI : public LivingAi
{
public:
	PlayerAI();
	~PlayerAI();

	virtual bool execute(LivingObject * obj);
};

