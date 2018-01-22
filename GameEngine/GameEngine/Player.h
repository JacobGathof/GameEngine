#pragma once

#include "MovableObject.h"

class Player : public MovableObject
{
public:
	Player(TextureType texture, Vector2f position, Vector2f scale);
	Player();
	~Player();

	virtual bool update(float delta_time);
};

