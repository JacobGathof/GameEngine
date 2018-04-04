#include "GoToPointAI.h"
#include "LivingObject.h"


GoToPointAI::GoToPointAI(Vector2f loc)
{
	dest = loc;
}

GoToPointAI::GoToPointAI()
{
}

GoToPointAI::~GoToPointAI()
{
}

bool GoToPointAI::execute(LivingObject * obj, float dt)
{
	if (obj->pos.distanceTo(dest) < obj->moveSpeed * dt) {
		obj->pos = dest;
		return true;
	}
	else {
		float dx = dest[0] - obj->pos[0];
		float dy = dest[1] - obj->pos[1];
		float angle = atan2(dy,dx);
		obj->pos[0] += cos(angle) * obj->moveSpeed * dt;
		obj->pos[1] += sin(angle) * obj->moveSpeed * dt;
	}
	return false;
}
