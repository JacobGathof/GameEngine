#pragma once

#include "Object.h"
#include "Item.h"
#include "InteractionObject.h"

class Chest : public Object
{
public:
	Chest(TextureType t, Vector2f& position, Vector2f& sc, AbstractAction* action);
	~Chest();
	virtual void interact();
};

