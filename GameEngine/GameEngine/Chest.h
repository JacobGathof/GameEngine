#pragma once

#include "Object.h"
#include "Item.h"
#include "InteractionObject.h"
#include "InteractableObject.h"

class Chest : public InteractableObject
{
public:
	Chest(TextureType t, Vector2f& position, Vector2f& sc, AbstractAction* action);
	~Chest();
	virtual void interact();
};

