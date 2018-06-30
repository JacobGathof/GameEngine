#pragma once
#include "AnimatedObject.h"

class Circle;

class InteractableObject : public AnimatedObject
{
public:
	InteractableObject(std::string& name, TextureType t, Vector2f& position, Vector2f& sc);
	virtual ~InteractableObject();

	virtual void interact();
	virtual void addAI(AI * ai);
	virtual void setInteraction(AbstractAction * i);
	virtual bool update(float dt);

	virtual void draw();

	bool intersects(InteractableObject* obj);
	Circle* getInteractionRadius();

	virtual bool executeAI(float dt, AI* ai);

protected:
	AbstractAction * interactObj;
	Circle* interactionRadius;
	bool interacting = false;
};

