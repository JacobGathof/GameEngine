#pragma once
#include "Object.h"

class AI;
class PlayerAI;

class Player : public Object
{
public:
	Player(ObjectData& data, PlayerAI * ai);
	virtual ~Player();

	virtual bool update(float delta_time);
	virtual bool collide(Object * o, Hitbox * h);
	virtual bool executeAI(float dt, AI* ai);

private:
	float lastX = 0;
	float lastY = 0;

	float health, maxHealth, stanima, currentStamina;
};

