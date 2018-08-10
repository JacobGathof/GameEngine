#include "CircleAI.h"
#include "InteractableObject.h"

CircleAI::CircleAI(Vector2f& c, float r, float s)
{
	radius = r;
	center = c;
	speed = s;
	fakePos = center + radius * Vector2f(1, 0);
}

CircleAI::~CircleAI()
{
}

bool CircleAI::execute(InteractableObject * obj, float dt)
{
	timer.update(dt);
	float f = timer.getTotalTime();
	fakePos = center + radius * Vector2f(cos(f*speed), sin(f*speed));
	obj->pos = Vector2f(((int)fakePos.x / 64) * 64, ((int)fakePos.y / 64) * 64);
	return false;
}
