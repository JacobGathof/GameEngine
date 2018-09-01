#pragma once

#include "Object.h"
#include "World.h"

class TransitionObject : public Object
{
public:
	TransitionObject(ObjectData& data, Room * r);
	virtual ~TransitionObject();

	virtual bool collide(Object * o, Hitbox * h);

private:
	Room * room;
};

