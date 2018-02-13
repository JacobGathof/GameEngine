#include "FollowAi.h"
#include "LivingObject.h"


FollowAi::FollowAi(LivingObject * obj)
{
	follow = obj;
}

FollowAi::~FollowAi()
{
}

bool FollowAi::execute(LivingObject * obj, float dt)
{
	if (obj->pos.distanceTo(follow->pos) < 300) {
		return false;
	}
	int dx = follow->pos[0] - obj->pos[0];
	int dy = follow->pos[1] - obj->pos[1];
	obj->pos[0] += dx * dt;
	obj->pos[1] += dy * dt;
	return true;
}
