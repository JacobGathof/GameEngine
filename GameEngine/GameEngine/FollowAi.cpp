#include "FollowAi.h"
#include "LivingObject.h"


FollowAi::FollowAi(LivingObject * obj)
{
	follow = obj;
}

FollowAi::~FollowAi()
{
}

bool FollowAi::execute(LivingObject * obj)
{
	if (obj->pos.distanceTo(follow->pos) < 300) {
		return false;
	}
	int dx = follow->pos[0] - obj->pos[0];
	int dy = follow->pos[1] - obj->pos[1];
	obj->pos[0] += dx / 50;
	obj->pos[1] += dy / 50;
	return true;
}
