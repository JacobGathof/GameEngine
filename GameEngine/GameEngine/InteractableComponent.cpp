#include "InteractableComponent.h"
#include "Circle.h"
#include "Object.h"
#include "GameState.h"
#include "ScriptManager.h"

InteractableComponent InteractableComponent::comp;

InteractableComponent::InteractableComponent()
{
	interactionRadius = new Circle(Vector2f(0, 0), 64);
	interactionRadius->color = Color::Red;
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
	GameState::applicationState.interactionName = parent->name;
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
	if (interacting) {
		if (!waiting && interactAction != 0) {
			waiting = true;
		}
		else if (ScriptManager::isRunning()) {
			interacting = false;
			waiting = false;
		}
		else if (waiting && interactAction != 0) {
			interactAction->run(dt);
			interacting = false;
			waiting = false;
		}
		else {
			interacting = false;
		}
	}

	return true;
}

void InteractableComponent::draw()
{
	interactionRadius->draw();
}

bool InteractableComponent::intersects(Object * obj)
{
	
	if (obj->hasTrait<InteractableComponent>()) {
		InteractableComponent* comp = obj->getComponent<InteractableComponent>();
		return comp->getInteractionRadius()->intersects(interactionRadius);
	}
	
	return false;
}

Circle * InteractableComponent::getInteractionRadius()
{
	return interactionRadius;
}
