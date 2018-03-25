#include "GoToOrthogonalPointAI.h"
#include "LivingObject.h"

GoToOrthogonalPointAI::GoToOrthogonalPointAI(Vector2f loc, bool yThenX)
{
	dest = loc;
	yFirst = yThenX;
}

GoToOrthogonalPointAI::~GoToOrthogonalPointAI()
{
}

bool GoToOrthogonalPointAI::execute(LivingObject * obj, float dt)
{
	if (yFirst) {
		if (abs(obj->pos[1] - dest[1]) < obj->moveSpeed * dt) {
			obj->pos[1] = dest[1];
			if (done) {
				return true;
			}
			done = !done;
			yFirst = false;
		}
		else {
			if (obj->pos[1] < dest[1]){
				obj->pos[1] += obj->moveSpeed * dt;
			}
			else {
				obj->pos[1] -= obj->moveSpeed * dt;
			}
		}
	}
	else {
		if (abs(obj->pos[0] - dest[0]) < obj->moveSpeed * dt) {
			obj->pos[0] = dest[0];
			if (done) {
				return true;
			}
			yFirst = true;
			done = !done;
		}
		else {
			if (obj->pos[0] < dest[0]) {
				obj->pos[0] += obj->moveSpeed * dt;
			}
			else {
				obj->pos[0] -= obj->moveSpeed * dt;
			}
		}
	}

	if (obj->pos.distanceTo(dest) < obj->moveSpeed * dt) {
		obj->pos = dest;
		return true;
	}
	else {
		float dx = dest[0] - obj->pos[0];
		float dy = dest[1] - obj->pos[1];
		float angle = (float)atan2(dy, dx);
		obj->pos[0] += cos(angle) * obj->moveSpeed * dt;
		obj->pos[1] += sin(angle) * obj->moveSpeed * dt;
	}
	return false;
	return false;
}
