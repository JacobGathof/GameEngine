#pragma once

#include "Object.h"
#include "Item.h"
#include "InteractionObject.h"
#include "InteractableObject.h"

class Chest : public InteractableObject
{
public:
	Chest(ObjectData& data, AbstractAction* action);
	~Chest();
	virtual void interact();
};

