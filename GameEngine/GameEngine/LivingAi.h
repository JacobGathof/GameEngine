#pragma once

#include "AI.h"
#include "LivingObject.h"

class LivingAi : public AI
{
public:
	LivingAi();
	~LivingAi();

	virtual bool execute(LivingObject * obj, float dt);
};

