#include "MovableObject.h"



MovableObject::MovableObject()
{
}


MovableObject::~MovableObject()
{
}

bool MovableObject::update(float delta_time)
{
	return false;
}

bool MovableObject::collide(Object o)
{
	return false;
}
