#pragma once

#include "MovableObject.h"
#include "PlayerAI.h"

class Player : public MovableObject
{
public:
	Player(TextureType texture, Vector2f position, Vector2f scale, PlayerAI * ai);
	Player();
	~Player();

	virtual bool update(float delta_time);
};

