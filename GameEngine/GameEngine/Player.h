#pragma once

#include "MovableObject.h"
#include "PlayerAI.h"

class Player : public LivingObject
{
public:
	Player(std::string name, TextureType texture, Vector2f position, Vector2f scale, PlayerAI * ai);
	~Player();

	virtual bool update(float delta_time);
	virtual bool collide(Object * o);

private:
	float lastX = 0;
	float lastY = 0;
};

