#pragma once

#include "AnimatedObject.h"

class MovableObject : public AnimatedObject
{
public:
	MovableObject();
	~MovableObject();

	float moveSpeed;
	Vector2f direction;

	virtual bool update(float delta_time);
	virtual bool collide(Object * o);
};

