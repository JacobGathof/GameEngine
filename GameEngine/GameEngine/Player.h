#pragma once

#include "MovableObject.h"
#include "PlayerAI.h"

class Player : public LivingObject
{
public:
	Player(TextureType texture, Vector2f position, Vector2f scale, PlayerAI * ai);
	~Player();

	virtual bool update(float delta_time);
	virtual bool collide(Object * o);
};

