#include "PlayerAI.h"
#include "Player.h"
#include "FastParticleSystem.h"
#include "DamageTag.h"

#include "MidiScheduler.h"
#include "AnimatedComponent.h"
#include "InteractableComponent.h"


PlayerAI::PlayerAI() : spline(Vector2f(0,0), Vector2f(0,0), Vector2f(0,0), Vector2f(0,0)), line(Vector2f(0,0), Vector2f(0,0)), line2(Vector2f(0,0), Vector2f(0,0))
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

	user->pos += Vector2f(xVel, yVel).normalize() * 256*dt;
	
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

	MidiEvent* me = MidiScheduler::queryMidiState();
	if (me != 0) {
		
	}

	AnimatedComponent* comp = user->getComponent<AnimatedComponent>();

	if (keyboard.down(VirtualKey::UP)){
		yVel = 1;
		comp->setAction(SpriteSheet::AnimationState::MOVE_UP);
	}
	if (keyboard.down(VirtualKey::DOWN)) {
		yVel = -1;
		comp->setAction(SpriteSheet::AnimationState::MOVE_DOWN);
	}
	if (keyboard.down(VirtualKey::LEFT)) {
		xVel = -1;
		comp->setAction(SpriteSheet::AnimationState::MOVE_LEFT);
	}
	if (keyboard.down(VirtualKey::RIGHT)) {
		xVel = 1;
		comp->setAction(SpriteSheet::AnimationState::MOVE_RIGHT);
	}

	if (xVel != 0 || yVel != 0) {
		//user->forward = Vector2f(xVel, yVel).normalize();
	}

	Vector2f mp = mouse.pos() - Vector2f(Screen::width, Screen::height) / 2;


	line.p1 = user->pos;
	spline.p4 = user->pos;

	if (numClicks == 0) {
		line.p2 = Screen::toWorldCoords(mouse.pos());
	}
	if (numClicks == 1) {
		line2.p2 = Screen::toWorldCoords(mouse.pos());
	}

	if (mouse.click()) {

		if (numClicks == 0) {
			line.p2 = Screen::toWorldCoords(mouse.pos());
			line2.p1 = Screen::toWorldCoords(mouse.pos());
			line2.p2 = Screen::toWorldCoords(mouse.pos());
		}if (numClicks == 1) {
			Vector2f a = Screen::toWorldCoords(mouse.pos()) - line.p1;
			Vector2f b = Vector2f(-(line.p2 - line.p1)[1], (line.p2 - line.p1)[0]);
			line2.p2 = (a.dot(b) / b.dot(b)) * b + line.p2;

			spline.p1 = user->pos;
			spline.p2 = line2.p2;
			spline.p3 = 2*line.p2  - line2.p2;
			spline.p4 = user->pos;

			leftClick(mp);

		}
		if (numClicks == 2) {
			line.p1 = user->pos;
			line.p2 = user->pos;
			line2.p1 = user->pos;
			line2.p2 = user->pos;

			spline.p1 = user->pos;
			spline.p2 = user->pos;
			spline.p3 = user->pos;
			spline.p4 = user->pos;
		}

		numClicks++;
		if (numClicks >= 3)
			numClicks = 0;

	}

}

void PlayerAI::processInteractKey()
{
	Object * closest = World::getInstance()->getNearestObject(user->pos);
	if (closest == 0)
		return;
	InteractableComponent* comp = closest->getComponent<InteractableComponent>();
	if (comp->intersects(user)) {
		comp->interact();
	}
}

void PlayerAI::processArrowUpKey()
{
	std::cout << user->pos << std::endl;
}

void PlayerAI::leftClick(Vector2f & pos)
{
	/*
	Vector2f direction = (pos - Screen::toScreenCoords(user->pos)).normalize();
	Boomerang * p = new Boomerang(std::string("_"), TextureType::TEXTURE_DAGON, user->pos, Vector2f(64, 64), direction, user);
	p->setPoints(spline.p1, spline.p2, spline.p3, spline.p4);
	World::getInstance()->addCObject(p);
	*/

	/*
	Vector2f direction = (pos - Screen::toScreenCoords(user->pos)).normalize();
	Projectile * p = new Projectile(ObjectData{ "_",  user->pos, Vector2f(64, 64), TextureType::ARROW_TEXTURE }, direction, user);
	World::getInstance()->addCObject(p);

	if (GameState::inv->getCurrentWeapon() == Res::get(WeaponType::SWORD)) {
		Vector2f direction = (pos - Screen::toScreenCoords(user->pos)).normalize();
		Projectile * p = new Boomerang(ObjectData{ "_",  user->pos, Vector2f(64, 64), TextureType::TEXTURE_DAGON }, direction, user);
		World::getInstance()->addCObject(p);
	}

	if (GameState::inv->getCurrentWeapon() == Res::get(WeaponType::BOW)) {
		Vector2f direction = (pos - Screen::toScreenCoords(user->pos)).normalize();
		Projectile * p = new Projectile(ObjectData{ "_",  user->pos, Vector2f(64, 64), TextureType::ARROW_TEXTURE }, direction, user);
		World::getInstance()->addCObject(p);
	}
	*/

}



