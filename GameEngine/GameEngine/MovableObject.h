#pragma once

#include "AnimatedObject.h"

class MovableObject : public AnimatedObject
{
public:
	MovableObject(TextureType t, Vector2f position, Vector2f sc);
	MovableObject();
	~MovableObject();

	float moveSpeed;
	Vector2f direction;

	virtual bool update(float delta_time);
	virtual bool collide(Object * o);
};

