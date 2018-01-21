#pragma once

#include "Object.h"
#include "World.h"

class TransitionObject : public Object
{
public:
	TransitionObject();
	~TransitionObject();

	Room room;

	virtual bool collide(Object * o);
};

