#pragma once
#include "AbstractObjectComponent.h"

class AbstractAction;
class Circle;

class InteractableComponent : public AbstractObjectComponent
{
public:
	InteractableComponent();
	~InteractableComponent();

	static InteractableComponent comp;
	static InteractableComponent* getComponent();

	void interact();
	void setInteraction(AbstractAction * i);

	bool update(float dt);
	void draw();
	
	bool intersects(Object* obj);
	Circle* getInteractionRadius();

protected:
	AbstractAction * interactAction;

	Circle* interactionRadius;
	bool interacting = false;
	bool interactionCount = 0;



};

