#include "PlayerAI.h"


PlayerAI::PlayerAI()
{
}

PlayerAI::~PlayerAI()
{
}

bool PlayerAI::execute(Object * obj)
{
	std::cout << "running AI";
	float movSpeed = .1f;
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
	obj->pos += Vector2f(x,y);

	return true;
}
