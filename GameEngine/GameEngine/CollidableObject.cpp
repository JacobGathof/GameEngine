#include "CollidableObject.h"
#include "CircleHitbox.h"


CollidableObject::CollidableObject(std::string& n, TextureType t, Vector2f& position, Vector2f& sc) :
	Object(n, t, position, sc)
{
	addHitbox(new CircleHitbox(Circle(Vector2f(0,0), 64), Vector2f(0,0)));
}


CollidableObject::~CollidableObject()
{
	for (auto hit : hitboxes) {
		delete hit;
	}
	if (enterTriggerAction != 0) {
		delete enterTriggerAction;
	}
	if (exitTriggerAction != 0) {
		delete exitTriggerAction;
	}
}


void CollidableObject::updateHitbox()
{
	for (Hitbox * hit : hitboxes) {
		hit->updatePos(pos);
	}
}


bool CollidableObject::collide(Object * o, Hitbox * h)
{
	return false;
}

bool CollidableObject::collide(CollidableObject * obj)
{
	trigger();
	return false;
}

void CollidableObject::drawHitboxes()
{
	for (Hitbox * h : hitboxes) {
		h->draw();
	}
}

bool CollidableObject::update(float dt)
{

	handleTriggers();
	triggered_past = triggered;
	triggered = false;

	updateHitbox();
	return Object::update(dt);
}


int CollidableObject::numHitboxes()
{
	return hitboxes.size();
}

void CollidableObject::addHitbox(Hitbox * h)
{
	hitboxes.add(h);
}

Hitbox * CollidableObject::getHitbox(int i)
{
	return hitboxes.get(i);
}



void CollidableObject::trigger()
{
	triggered = true;
}

void CollidableObject::setExitTrigger(AbstractAction * a)
{
	if (exitTriggerAction != 0) {
		delete exitTriggerAction;
	}
	exitTriggerAction = a;
}

void CollidableObject::setEnterTrigger(AbstractAction * a)
{
	if (enterTriggerAction != 0) {
		delete enterTriggerAction;
	}
	enterTriggerAction = a;
}

void CollidableObject::handleTriggers()
{
	if (triggered && !triggered_past) {
		onEnterTrigger();
	}
	if (!triggered && triggered_past) {
		onExitTrigger();
	}
}

void CollidableObject::onEnterTrigger()
{
	if (enterTriggerAction != 0) {
		enterTriggerAction->run();
	}
}

void CollidableObject::onExitTrigger()
{
	if (exitTriggerAction != 0) {
		exitTriggerAction->run();
	}
}
