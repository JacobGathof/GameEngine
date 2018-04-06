#pragma once

#include "LivingAi.h"
#include "Vector2f.h"

class GoToOrthogonalPointAI : public LivingAi
{
public:
	GoToOrthogonalPointAI(Vector2f loc, bool yThenX);
	~GoToOrthogonalPointAI();

	bool done = false;
	virtual bool execute(LivingObject * obj, float dt);

private:
	Vector2f dest;
	bool yFirst = false;
};

