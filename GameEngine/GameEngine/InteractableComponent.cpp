#include "InteractableComponent.h"
#include "Circle.h"
#include "Object.h"

InteractableComponent InteractableComponent::comp;

InteractableComponent::InteractableComponent()
{
}


InteractableComponent::~InteractableComponent()
{
	if (interactAction != 0) {
		delete interactAction;
	}
	if (interactionRadius != 0) {
		delete interactionRadius;
	}
}

InteractableComponent * InteractableComponent::getComponent()
{
	return &comp;
}

void InteractableComponent::interact()
{
	interacting = true;
	interactionCount++;
}

void InteractableComponent::setInteraction(AbstractAction * i)
{
	if (interactAction != 0) {
		delete interactAction;
	}

	interactAction = i;
}

bool InteractableComponent::update(float dt)
{
	interactionRadius->center = parent->pos;
	if (interacting && interactAction != 0) {
		int status = interactAction->run(dt);
		interacting = (status == 0);
		if (!interacting) {
			interactAction->reset();
		}
	}

	return true;
}

void InteractableComponent::draw()
{
	//Nothing
}

bool InteractableComponent::intersects(Object * obj)
{
	/*
	auto a = obj->getComponent<InteractableComponent>();

	return obj->getInteractionRadius()->intersects(interactionRadius);
	*/
	return false;
}

Circle * InteractableComponent::getInteractionRadius()
{
	return interactionRadius;
}
