#pragma once

#include "Object.h"
#include "World.h"

class TransitionObject : public CollidableObject
{
public:
	TransitionObject(TextureType t, Vector2f& position, Vector2f& sc, Room * r);
	virtual ~TransitionObject();

	virtual bool collide(Object * o, Hitbox * h);

private:
	Room * room;
};

