#include "FollowAI.h"
#include "LivingObject.h"


FollowAI::FollowAI(LivingObject * obj)
{
	follow = obj;
}

FollowAI::~FollowAI()
{
}

bool FollowAI::execute(LivingObject * obj, float dt)
{
	if (moving == true && obj->pos.distanceTo(follow->pos) < 300) {
		moving = false;
		return false;
	}
	else if (moving == false && obj->pos.distanceTo(follow->pos) > 500) {
		moving = true;
	}
	if (moving) {
		int dx = follow->pos[0] - obj->pos[0];
		int dy = follow->pos[1] - obj->pos[1];
		obj->pos[0] += dx * dt;
		obj->pos[1] += dy * dt;
	}
	return true;
}
