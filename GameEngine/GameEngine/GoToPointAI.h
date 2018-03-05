#pragma once

#include "LivingAi.h"

class GoToPointAI : public LivingAi
{
public:
	GoToPointAI(Vector2f loc);
	GoToPointAI();
	~GoToPointAI();

	Vector2f dest;

	virtual bool execute(LivingObject * obj, float dt);
};

