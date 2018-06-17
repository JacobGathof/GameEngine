#pragma once
#include "LivingObject.h"

class AI;
class PlayerAI;

class Player : public LivingObject
{
public:
	Player(std::string& name, TextureType texture, Vector2f& position, Vector2f& scale, PlayerAI * ai);
	virtual ~Player();

	virtual bool update(float delta_time);
	virtual bool collide(Object * o, Hitbox * h);
	virtual bool executeAI(float dt, AI* ai);

private:
	float lastX = 0;
	float lastY = 0;

	float health, maxHealth, stanima, currentStamina;
};

