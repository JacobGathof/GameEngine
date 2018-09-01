#pragma once

#include "AI.h"
#include "Vector2f.h"

class GoToOrthogonalPointAI : public AI
{
public:
	GoToOrthogonalPointAI(Vector2f loc, bool yThenX);
	~GoToOrthogonalPointAI();

	bool done = false;
	virtual bool execute(Object * obj, float dt);

private:
	Vector2f dest;
	bool yFirst = false;
};

