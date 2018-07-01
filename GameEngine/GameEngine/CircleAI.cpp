#include "CircleAI.h"
#include "InteractableObject.h"

CircleAI::CircleAI(Vector2f& c, float r, float s)
{
	radius = r;
	center = c;
	speed = s;
}

CircleAI::~CircleAI()
{
}

bool CircleAI::execute(InteractableObject * obj, float dt)
{
	timer.update(dt);
	float f = timer.getTotalTime();
	obj->pos = center + radius*Vector2f(cos(f*speed), sin(f*speed));
	return false;
}
