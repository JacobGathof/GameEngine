#pragma once
#include "AnimatedObject.h"

class Circle;

class InteractableObject : public AnimatedObject
{
public:
	InteractableObject(ObjectData& data);
	virtual ~InteractableObject();

	virtual void interact();
	virtual void setInteraction(AbstractAction * i);

	virtual bool update(float dt);
	virtual void draw();
	virtual bool collide(CollidableObject* obj);


	virtual void trigger(Object* obj);
	virtual void setEnterTrigger(AbstractAction* a);
	virtual void setExitTrigger(AbstractAction* a);
	virtual void setOnDestroyTrigger(AbstractAction* a);
	virtual void handleTriggers();

	virtual void onEnterTrigger();
	virtual void onExitTrigger();


	bool intersects(InteractableObject* obj);
	Circle* getInteractionRadius();

	virtual bool executeAI(float dt, AI* ai);

protected:
	AbstractAction * interactObj;

	Circle* interactionRadius;
	bool interacting = false;
	bool interactionCount = 0;


	bool triggered = false;
	bool triggered_past = false;
	AbstractAction* exitTriggerAction;
	AbstractAction* enterTriggerAction;
	AbstractAction* destroyTriggerAction;

	Object* triggerSubject;
};

