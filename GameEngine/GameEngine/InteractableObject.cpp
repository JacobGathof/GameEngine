#include "InteractableObject.h"
#include "Circle.h"


InteractableObject::InteractableObject(std::string& name, TextureType t, Vector2f& position, Vector2f& sc) : 
	AnimatedObject(name, t, position, sc)
{
	interactionRadius = new Circle(position, sc[0]);
	interactionRadius->color = Color::DarkBlue;
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
	delete interactionRadius;
}



void InteractableObject::interact()
{
	std::cout << "Interact" << std::endl;
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
	if (interacting) {
		interacting = !interactObj->run(dt);
	}
	return AnimatedObject::update(dt);
}

void InteractableObject::draw()
{
	AnimatedObject::draw();
	interactionRadius->draw();
	drawHitboxes();
}

bool InteractableObject::collide(CollidableObject * obj)
{
	trigger();
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





void InteractableObject::trigger()
{
	triggered = true;
}

void InteractableObject::setExitTrigger(AbstractAction * a)
{
	if (exitTriggerAction != 0) {
		delete exitTriggerAction;
	}
	exitTriggerAction = a;
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