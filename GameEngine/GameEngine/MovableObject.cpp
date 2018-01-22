#include "MovableObject.h"



MovableObject::MovableObject(TextureType t, Vector2f position, Vector2f sc) : AnimatedObject(t, position, sc)
{
	
}

MovableObject::MovableObject()
{
}


MovableObject::~MovableObject()
{
}

bool MovableObject::update(float delta_time)
{
	return AnimatedObject::update(delta_time);
}

bool MovableObject::collide(Object * o)
{
	return false;
}
