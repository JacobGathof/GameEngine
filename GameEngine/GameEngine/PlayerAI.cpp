#include "PlayerAI.h"
#include "LivingObject.h"

PlayerAI::PlayerAI()
{
}

PlayerAI::~PlayerAI()
{
}

bool PlayerAI::execute(LivingObject * o)
{
	if (user == nullptr) {
		user = o;
	}
	LivingObject * obj = (LivingObject *)o;
	
	obj->pos += Vector2f(xVel, yVel);

	return true;
}

void PlayerAI::receiveInput(KeyMaps key, int state)
{
	if (state == 2) {
		return;
	}
	if (user == nullptr) {
		return;
	}

	if (state == 1 && key == KeyMaps::KEY_INTERACT) {
		Object * closest = World::getInstance()->getNearestObject(user->pos);
		std::cout << sqrt(pow(closest->pos[0] - user->pos[0], 2) + pow(closest->pos[1] - user->pos[1], 2)) << std::endl;
		if (sqrt(pow(closest->pos[1] - user->pos[1], 2) + pow(closest->pos[1] - user->pos[0], 2)) < 1) {
			closest->interact();
		}
	}
	int modifier = (state * 2) - 1; //Released = -1    Pressed = 1

	if (key == KeyMaps::KEY_UP) {
		yVel += modifier * user->moveSpeed;
	}
	else if (key == KeyMaps::KEY_DOWN) {
		yVel += -modifier * user->moveSpeed;
	}
	if (key == KeyMaps::KEY_LEFT) {
		xVel += -modifier * user->moveSpeed;
	}
	else if (key == KeyMaps::KEY_RIGHT) {
		xVel += modifier * user->moveSpeed;
	}

}



