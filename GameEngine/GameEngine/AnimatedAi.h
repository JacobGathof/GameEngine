#pragma once

#include "AI.h"

class AnimatedAI : public AI
{
public:
	AnimatedAI();
	~AnimatedAI();

	virtual bool execute(AnimatedObject * obj, float dt);
};

