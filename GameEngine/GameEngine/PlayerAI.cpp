#include "PlayerAI.h"
#include "LivingObject.h"

PlayerAI::PlayerAI()
{
}

PlayerAI::~PlayerAI()
{
}

bool PlayerAI::execute(LivingObject * o, float dt)
{
	if (user == nullptr) {
		user = o;
	}
	LivingObject * obj = (LivingObject *)o;

	obj->pos += Vector2f(xVel * dt, yVel * dt);

	return true;
}

void PlayerAI::receiveInput(Keyboard& keyboard)
{
	if (user == nullptr) {
		return;
	}

	if (keyboard.getKeyState(VirtualKey::INTERACT) == KeyState::PRESS){
		Object * closest = World::getInstance()->getNearestObject(user->pos);
		if (closest->pos.distanceTo(user->pos) < 40) {
			closest->interact();
		}
	}

	yVel = 0;
	xVel = 0;


	if (keyboard.getKeyState(VirtualKey::UP) == KeyState::DOWN){
		yVel = user->moveSpeed;
	}
	if (keyboard.getKeyState(VirtualKey::DOWN) == KeyState::DOWN) {
		yVel = -user->moveSpeed;
	}
	if (keyboard.getKeyState(VirtualKey::LEFT) == KeyState::DOWN) {
		xVel = -user->moveSpeed;
	}
	if (keyboard.getKeyState(VirtualKey::RIGHT) == KeyState::DOWN) {
		xVel = user->moveSpeed;
	}

}



