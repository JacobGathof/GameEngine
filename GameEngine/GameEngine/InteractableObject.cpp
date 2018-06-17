#include "InteractableObject.h"
#include "Circle.h"


InteractableObject::InteractableObject(std::string& name, TextureType t, Vector2f& position, Vector2f& sc) : 
	AnimatedObject(name, t, position, sc)
{
	interactionRadius = new Circle(position, sc[0]);
}


InteractableObject::~InteractableObject()
{
	delete interactObj;
	delete interactionRadius;
}



void InteractableObject::interact()
{
	if (stalled) {
		return;
	}
	interactObj->run();
}

void InteractableObject::setAI(AI * a)
{
	if (stalled) {
		return;
	}
	if (defaultAI == nullptr) {
		defaultAI = a;
	}
	else {
		aiQueue.add(a);
	}
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
	interactionRadius->center = pos;
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