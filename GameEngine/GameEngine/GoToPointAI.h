#pragma once

#include "LivingAi.h"
#include "Vector2f.h"

class GoToPointAI : public LivingAi
{
public:
	GoToPointAI(Vector2f loc);
	GoToPointAI();
	~GoToPointAI();

	Vector2f dest;
	float speed = -1;

	virtual bool execute(LivingObject * obj, float dt);

private:
};

