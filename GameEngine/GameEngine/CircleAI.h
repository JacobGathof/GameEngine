#pragma once
#include "AI.h"
#include "Timer.h"
#include "Vector2f.h"

class CircleAI : public AI
{
public:
	CircleAI(Vector2f& center, float radius, float speed);
	~CircleAI();

	virtual bool execute(InteractableObject * obj, float dt);

private:
	float radius;
	float speed;
	Vector2f center;
	Timer timer;
};

