#include "RunAwayAI.h"
#include "LivingObject.h"

RunAwayAI::RunAwayAI(LivingObject * obj)
{
	object = obj;
}

RunAwayAI::~RunAwayAI()
{
}

bool RunAwayAI::execute(LivingObject * obj, float dt)
{

	if (moving == true && obj->pos.distanceTo(object->pos) > 1200) {
		moving = false;
		return false;
	}
	else if (moving == false && obj->pos.distanceTo(object->pos) < 1000) {
		moving = true;
	}
	if (moving) {
		float dx = object->pos[0] - obj->pos[0];
		float dy = object->pos[1] - obj->pos[1];
		obj->pos[0] -= dx * dt;
		obj->pos[1] -= dy * dt;
	}
	
	return true;
}
