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

	if (obj->pos.distanceTo(object->pos) > 1000) {
		return false;
	}
	int dx = object->pos[0] - obj->pos[0];
	int dy = object->pos[1] - obj->pos[1];
	obj->pos[0] -= dx * dt;
	obj->pos[1] -= dy * dt;
	return true;
}
