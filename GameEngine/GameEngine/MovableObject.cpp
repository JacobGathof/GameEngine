#include "MovableObject.h"



MovableObject::MovableObject(std::string& name, TextureType t, Vector2f& position, Vector2f& sc) : AnimatedObject(name, t, position, sc)
{
	
}

MovableObject::~MovableObject()
{
}

bool MovableObject::update(float delta_time)
{
	return AnimatedObject::update(delta_time);
}

bool MovableObject::collide(Object * o, Hitbox * h)
{
	return false;
}
