#include "CollidableComponent.h"
#include "Hitbox.h"
#include "Object.h"
#include "CircleHitbox.h"

CollidableComponent CollidableComponent::comp;

CollidableComponent::CollidableComponent()
{
	addHitbox(new CircleHitbox(128, Vector2f(0, 0)));
}


CollidableComponent::~CollidableComponent()
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
	if (destroyTriggerAction != 0) {
		destroyTriggerAction->run(0);
		delete destroyTriggerAction;
	}
}

CollidableComponent * CollidableComponent::getComponent()
{
	return &comp;
}

void CollidableComponent::drawHitboxes()
{
	for (Hitbox * h : hitboxes) {
		h->draw();
	}
}

bool CollidableComponent::update(float dt)
{

	handleTriggers();
	triggered_past = triggered;
	triggered = false;


	updateHitbox();
	return true;
}

void CollidableComponent::addHitbox(Hitbox * h)
{
	hitboxes.add(h);
}

Hitbox * CollidableComponent::getHitbox(int i)
{
	return hitboxes.get(i);
}

int CollidableComponent::numHitboxes()
{
	return hitboxes.size();
}

void CollidableComponent::updateHitbox()
{
	for (Hitbox * hit : hitboxes) {
		hit->updatePos(parent->pos);
	}
}




void CollidableComponent::trigger(Object* obj)
{
	triggered = true;
	triggerSubject = obj;
}

void CollidableComponent::setExitTrigger(AbstractAction * a)
{
	if (exitTriggerAction != 0) {
		delete exitTriggerAction;
	}
	exitTriggerAction = a;
}

void CollidableComponent::setOnDestroyTrigger(AbstractAction * a)
{
	if (destroyTriggerAction != 0) {
		delete destroyTriggerAction;
	}
	destroyTriggerAction = a;
}

void CollidableComponent::setEnterTrigger(AbstractAction * a)
{
	if (enterTriggerAction != 0) {
		delete enterTriggerAction;
	}
	enterTriggerAction = a;
}

void CollidableComponent::handleTriggers()
{
	if (triggered && !triggered_past) {
		onEnterTrigger();
	}
	if (!triggered && triggered_past) {
		onExitTrigger();
	}
}

void CollidableComponent::onEnterTrigger()
{
	if (enterTriggerAction != 0) {
		enterTriggerAction->run();
	}
}

void CollidableComponent::onExitTrigger()
{
	if (exitTriggerAction != 0) {
		exitTriggerAction->run();
	}
}