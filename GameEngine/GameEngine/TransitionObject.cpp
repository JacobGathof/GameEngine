#include "TransitionObject.h"



TransitionObject::TransitionObject(TextureType t, Vector2f& position, Vector2f& sc, Room * r) : 
	CollidableObject(std::string("trans"), t, position, sc)
{
	isStatic = true;
	room = r;
	weight = Weight::GHOST;
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
