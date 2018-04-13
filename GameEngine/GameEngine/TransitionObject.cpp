#include "TransitionObject.h"



TransitionObject::TransitionObject(TextureType t, Vector2f position, Vector2f sc, Room * r) : Object("trans", t, position, sc)
{
	isStatic = true;
	room = r;
}

TransitionObject::TransitionObject(Vector2f position, Vector2f sc, Room * r) : Object("trans", TextureType::TEXTURE_DEFAULT, position, sc)
{
	isStatic = true;
	room = r;
}

TransitionObject::~TransitionObject()
{
}

bool TransitionObject::collide(Object * o, Hitbox * h)
{
	World * world = World::getInstance();
	if (o != world->getObject(std::string("Melody"))) {
		return true;
	}
	world->transition(room);
	return false;
}
