#include "TransitionObject.h"



TransitionObject::TransitionObject(TextureType t, Vector2f& position, Vector2f& sc, Room * r) : Object(std::string("trans"), t, position, sc)
{
	room = r;
}

TransitionObject::TransitionObject(Vector2f& position, Vector2f& sc, Room * r) : Object(std::string("trans"), TextureType::TEXTURE_DEFAULT, position, sc)
{
	room = r;
}

TransitionObject::~TransitionObject()
{
}

bool TransitionObject::collide(Object * o, Hitbox * h)
{
	World * world = World::getInstance();
	world->transition(room);
	return true;
}
