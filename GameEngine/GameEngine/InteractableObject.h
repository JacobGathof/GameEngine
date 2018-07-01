#pragma once
#include "AnimatedObject.h"

class Circle;

class InteractableObject : public AnimatedObject
{
public:
	InteractableObject(std::string& name, TextureType t, Vector2f& position, Vector2f& sc);
	virtual ~InteractableObject();

	virtual void interact();
	virtual void setInteraction(AbstractAction * i);

	virtual void trigger();
	virtual void setTrigger(AbstractAction* a);

	virtual bool update(float dt);

	virtual void draw();

	bool intersects(InteractableObject* obj);
	Circle* getInteractionRadius();

	virtual bool executeAI(float dt, AI* ai);

protected:
	AbstractAction * interactObj;
	AbstractAction* triggerAction;

	Circle* interactionRadius;
	bool interacting = false;
	bool triggered = false;

	bool interactionCount = 0;
};

