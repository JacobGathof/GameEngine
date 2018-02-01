#include "GoToPointAI.h"
#include "LivingObject.h"


GoToPointAI::GoToPointAI(Vector2f loc)
{
	dest = loc;
}

GoToPointAI::~GoToPointAI()
{
}

bool GoToPointAI::execute(LivingObject * obj)
{
	if (obj->pos.distanceTo(dest) < obj->moveSpeed) {
		obj->pos = dest;
	}
	else {
		int dx = dest[0] - obj->pos[0];
		int dy = dest[1] - obj->pos[1];
		
		float angle = atan2(dy,dx);
		obj->pos[0] += cos(angle) * obj->moveSpeed;
		obj->pos[1] += sin(angle) * obj->moveSpeed;
	}
	return false;
}
