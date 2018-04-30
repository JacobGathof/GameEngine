#include "GoToPointAI.h"
#include "LivingObject.h"


GoToPointAI::GoToPointAI(Vector2f loc, float speed)
{
	dest = loc;
	sp = speed;
}

GoToPointAI::GoToPointAI()
{
}

GoToPointAI::~GoToPointAI()
{
}

bool GoToPointAI::execute(LivingObject * obj, float dt)
{
	float speed = obj->moveSpeed;
	if (sp != -1) {
		speed = sp;
	}

	if (obj->pos.distanceTo(dest) < speed * dt) {
		obj->pos = dest;
		
		return true;
	}
	else {
		float dx = dest[0] - obj->pos[0];
		float dy = dest[1] - obj->pos[1];
		float angle = atan2(dy,dx);
		obj->pos[0] += cos(angle) * speed * dt;
		obj->pos[1] += sin(angle) * speed * dt;
	}
	return false;
}
