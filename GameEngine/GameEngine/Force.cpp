#include "Force.h"



Force::Force(Vector2f& f)
{
	value = f;
}


Force::~Force()
{
}

bool Force::update(float dt)
{
	value -= value * friction * dt;
	return (value.lengthSquared() >= 1);
}
