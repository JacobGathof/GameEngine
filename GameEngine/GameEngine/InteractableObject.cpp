#include "InteractableObject.h"
#include "Circle.h"


InteractableObject::InteractableObject(ObjectData& data) : AnimatedObject(data)
{
	interactionRadius = new Circle(pos, scale[0]);
	interactionRadius->color = Color::Blue;
}


InteractableObject::~InteractableObject()
{
	if (interactObj != 0) {
		delete interactObj;
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
	delete interactionRadius;
}



void InteractableObject::interact()
{
	interacting = true;
	interactionCount++;
}


void InteractableObject::setInteraction(AbstractAction * i)
{
	if (interactObj != 0) {
		delete interactObj;
	}

	interactObj = i;
}



bool InteractableObject::update(float dt)
{

	handleTriggers();
	triggered_past = triggered;
	triggered = false;


	interactionRadius->center = pos;
	if (interacting && interactObj != 0) {
		int status = interactObj->run(dt);
		interacting = (status==0);
		if (!interacting) {
			interactObj->reset();
		}
	}
	return AnimatedObject::update(dt);
}

void InteractableObject::draw()
{
	AnimatedObject::draw();
	//interactionRadius->draw();
}

bool InteractableObject::collide(CollidableObject * obj)
{
	trigger(obj);
	return false;
}

bool InteractableObject::intersects(InteractableObject * obj)
{
	return obj->getInteractionRadius()->intersects(interactionRadius);
}

Circle* InteractableObject::getInteractionRadius()
{
	return interactionRadius;
}

bool InteractableObject::executeAI(float dt, AI * ai)
{
	return ai->execute(this, dt);
}





void InteractableObject::trigger(Object* obj)
{
	triggered = true;
	triggerSubject = obj;
}

void InteractableObject::setExitTrigger(AbstractAction * a)
{
	if (exitTriggerAction != 0) {
		delete exitTriggerAction;
	}
	exitTriggerAction = a;
}

void InteractableObject::setOnDestroyTrigger(AbstractAction * a)
{
	if (destroyTriggerAction != 0) {
		delete destroyTriggerAction;
	}
	destroyTriggerAction = a;
}

void InteractableObject::setEnterTrigger(AbstractAction * a)
{
	if (enterTriggerAction != 0) {
		delete enterTriggerAction;
	}
	enterTriggerAction = a;
}

void InteractableObject::handleTriggers()
{
	if (triggered && !triggered_past) {
		onEnterTrigger();
	}
	if (!triggered && triggered_past) {
		onExitTrigger();
	}
}

void InteractableObject::onEnterTrigger()
{
	if (enterTriggerAction != 0) {
		enterTriggerAction->run();
	}
}

void InteractableObject::onExitTrigger()
{
	if (exitTriggerAction != 0) {
		exitTriggerAction->run();
	}
}