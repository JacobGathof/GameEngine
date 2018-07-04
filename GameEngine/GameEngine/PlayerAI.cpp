#include "PlayerAI.h"
#include "Player.h"
#include "Projectile.h"
#include "FastParticleSystem.h"
#include "DamageTag.h"

PlayerAI::PlayerAI()
{
}

PlayerAI::~PlayerAI()
{
}

bool PlayerAI::execute(Player * o, float dt)
{
	if (user == 0) {
		user = o;
	}

	user->pos += Vector2f(xVel, yVel) * dt;
	
	return true;
}

void PlayerAI::receiveInput(Keyboard& keyboard, Mouse& mouse)
{

	if (user == 0) {
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
		user->setAction(SpriteSheet::AnimationState::MOVE_UP);
	}
	if (keyboard.down(VirtualKey::DOWN)) {
		yVel = -user->moveSpeed;
		user->setAction(SpriteSheet::AnimationState::MOVE_DOWN);
	}
	if (keyboard.down(VirtualKey::LEFT)) {
		xVel = -user->moveSpeed;
		user->setAction(SpriteSheet::AnimationState::MOVE_LEFT);
	}
	if (keyboard.down(VirtualKey::RIGHT)) {
		xVel = user->moveSpeed;
		user->setAction(SpriteSheet::AnimationState::MOVE_RIGHT);
	}

	if (xVel != 0 || yVel != 0) {
		//user->forward = Vector2f(xVel, yVel).normalize();
	}

	if (mouse.click()) {
		leftClick(mouse.pos() - Vector2f(400,400));
	}

}

void PlayerAI::processInteractKey()
{
	InteractableObject * closest = World::getInstance()->getNearestObject(user->pos);
	if (closest == 0)
		return;
	if (closest->intersects(user)) {
		closest->interact();
	}
}

void PlayerAI::processArrowUpKey()
{
	std::cout << user->pos << std::endl;
}

void PlayerAI::leftClick(Vector2f & pos)
{
	
	Vector2f direction = (pos - Screen::toScreenCoords(user->pos)).normalize();
	Projectile * p = new Projectile(std::string("_"), TextureType::ARROW_TEXTURE, user->pos, Vector2f(64, 64), direction, user);
	World::getInstance()->addCObject(p);

}



