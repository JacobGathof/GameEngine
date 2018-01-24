#pragma once

#include "LivingAi.h"
#include "Input.h"
#include "LivingObject.h"

class PlayerAI : public LivingAi
{
public:
	PlayerAI();
	~PlayerAI();

	virtual bool execute(void * obj);
};

