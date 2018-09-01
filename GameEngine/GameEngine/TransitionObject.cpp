#include "TransitionObject.h"



TransitionObject::TransitionObject(ObjectData& data, Room * r) : Object(data)
{
	isStatic = true;
	room = r;
	//weight = Weight::GHOST;
}

TransitionObject::~TransitionObject()
{
}

bool TransitionObject::collide(Object * o, Hitbox * h)
{
	World * world = World::getInstance();
	if (o != world->getObject(std::string("Player"))) {
		return true;
	}
	world->transition(room);
	return false;
}
