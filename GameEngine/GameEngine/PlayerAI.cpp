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

	obj->direction = Vector2f(xVel, yVel);

	obj->pos += obj->direction * dt;
	
	return true;
}

void PlayerAI::receiveInput(Keyboard& keyboard)
{
	if (user == nullptr) {
		return;
	}

	
	if (keyboard.press(VirtualKey::INTERACT)){
		this->processInteractKey();
	}

	if (keyboard.press(VirtualKey::ARROW_UP)) {
		this->processArrowUpKey();
	}

	yVel = 0;
	xVel = 0;


	if (keyboard.down(VirtualKey::UP)){
		yVel = user->moveSpeed;
	}
	if (keyboard.down(VirtualKey::DOWN)) {
		yVel = -user->moveSpeed;
	}
	if (keyboard.down(VirtualKey::LEFT)) {
		xVel = -user->moveSpeed;
	}
	if (keyboard.down(VirtualKey::RIGHT)) {
		xVel = user->moveSpeed;
	}

	if (xVel != 0 || yVel != 0) {
		user->forward = Vector2f(xVel, yVel).normalize();
	}

}

void PlayerAI::processInteractKey()
{
	Object * closest = World::getInstance()->getNearestObject(user->pos);
	if (closest->pos.distanceTo(user->pos) < 1024) {
		closest->interact();
	}
}

void PlayerAI::processArrowUpKey()
{
	std::cout << user->pos << std::endl;
}



