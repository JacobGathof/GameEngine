#pragma once

#include "Object.h"
#include "World.h"

class TransitionObject : public Object
{
public:
	TransitionObject(TextureType t, Vector2f position, Vector2f sc, Room * r);
	TransitionObject(Vector2f position, Vector2f sc, Room * r);
	~TransitionObject();

	virtual bool collide(Object * o, Hitbox * h);

private:
	Room * room;
};

