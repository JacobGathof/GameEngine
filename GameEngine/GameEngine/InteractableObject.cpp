#include "InteractableObject.h"
#include "Circle.h"


InteractableObject::InteractableObject(std::string& name, TextureType t, Vector2f& position, Vector2f& sc) : 
	AnimatedObject(name, t, position, sc)
{
	interactionRadius = new Circle(position, sc[0]);
}


InteractableObject::~InteractableObject()
{
	if (interactObj != 0) {
		delete interactObj;
	}
	if (triggerAction != 0) {
		delete triggerAction;
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

void InteractableObject::trigger()
{
	triggered = true;
}

void InteractableObject::setTrigger(AbstractAction * a)
{
	if (triggerAction != 0) {
		delete triggerAction;
	}
	triggerAction = a;
}

bool InteractableObject::update(float dt)
{
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
