#pragma once
#include "Object.h"

class AI;

class Player : public Object
{
public:
	Player(ObjectData& data);
	virtual ~Player();

	virtual bool update(float delta_time);
	virtual bool collide(Object * o, Hitbox * h);

private:
	float lastX = 0;
	float lastY = 0;

	float health, maxHealth, stanima, currentStamina;
};

