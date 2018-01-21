#include "MovableObject.h"



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
