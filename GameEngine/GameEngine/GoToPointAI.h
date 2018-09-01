#pragma once

#include "AI.h"
#include "Vector2f.h"

class GoToPointAI : public AI
{
public:
	GoToPointAI(Vector2f loc, float speed = -1);
	GoToPointAI();
	~GoToPointAI();

	Vector2f dest;
	float speed = -1;

	virtual bool execute(Object * obj, float dt);

private:
};

