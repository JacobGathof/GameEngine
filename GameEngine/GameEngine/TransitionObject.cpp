#include "TransitionObject.h"



TransitionObject::TransitionObject()
{
}


TransitionObject::~TransitionObject()
{
}

bool TransitionObject::collide(Object * o)
{
	World * world = World::getInstance();
	world->transition(&room);
	return true;
}
