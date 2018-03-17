#pragma once

#include "AI.h"

class LivingAi : public AI
{
public:
	LivingAi();
	~LivingAi();

	virtual bool execute(LivingObject * obj, float dt);
};

