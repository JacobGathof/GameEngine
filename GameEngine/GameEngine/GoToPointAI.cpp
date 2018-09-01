#include "GoToPointAI.h"
#include "Object.h"


GoToPointAI::GoToPointAI(Vector2f loc, float sp)
{
	dest = loc;
	speed = sp;
}

GoToPointAI::GoToPointAI()
{
}

GoToPointAI::~GoToPointAI()
{
}

bool GoToPointAI::execute(Object * obj, float dt)
{
	//float sp = obj->moveSpeed;
	float sp = 10;
	if (speed > -1) {
		sp = speed;
	}


	if (obj->pos.distanceTo(dest) < sp * dt) {
		obj->pos = dest;
		
		return true;
	}
	else {
		float dx = dest[0] - obj->pos[0];
		float dy = dest[1] - obj->pos[1];
		float angle = atan2(dy,dx);
		obj->pos[0] += cos(angle) * sp * dt;
		obj->pos[1] += sin(angle) * sp * dt;
	}
	return false;
}
