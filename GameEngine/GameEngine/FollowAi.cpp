#include "FollowAI.h"
#include "LivingObject.h"


FollowAI::FollowAI(Object * obj)
{
	follow = obj;
}

FollowAI::~FollowAI()
{
}

bool FollowAI::execute(Object * obj, float dt)
{
	if (moving == true && obj->pos.distanceTo(follow->pos) < 128) {
		moving = false;
		return false;
	}
	else if (moving == false && obj->pos.distanceTo(follow->pos) > 256) {
		moving = true;
	}
	if (moving) {
		float dx = follow->pos[0] - obj->pos[0];
		float dy = follow->pos[1] - obj->pos[1];
		Vector2f dir = Vector2f(dx, dy).normalize();
		Vector2f odir = Vector2f(((int)(dir[0] * 2.0f) / 2.0f), ((int)(dir[1] * 2.0f) / 2.0f));

		std::cout << odir << std::endl;

		obj->pos += odir.normalize() * dt * 256;
	}
	return true;
}
