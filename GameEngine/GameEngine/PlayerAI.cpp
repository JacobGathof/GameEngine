#include "PlayerAI.h"
#include "LivingObject.h"

PlayerAI::PlayerAI()
{
}

PlayerAI::~PlayerAI()
{
}

bool PlayerAI::execute(void * o)
{
	LivingObject * obj = (LivingObject *)o;
	float movSpeed = .03f;
	float x = 0;
	float y = 0;

	//Fix This
	for (char c : Input::keysDown) {
		if (c == 'w') {
			y += movSpeed;
		}
		else if (c == 's') {
			y -= movSpeed;
		}
		if (c == 'a') {
			x -= movSpeed;
		}
		else if (c == 'd') {
			x += movSpeed;
		}
	}
	obj->pos += Vector2f(x, y);

	if (Input::keys[69]) {
		Object * closest = World::getInstance()->getNearestObject(obj->pos);
		std::cout << sqrt(pow(closest->pos[0] - obj->pos[0], 2) + pow(closest->pos[1] - obj->pos[1], 2)) << std::endl;
		if (sqrt(pow(closest->pos[1] - obj->pos[1], 2) + pow(closest->pos[1] - obj->pos[0], 2)) < 1) {
			closest->interact();
		}
	}

	return true;
}



