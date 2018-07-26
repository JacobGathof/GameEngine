#include "Chest.h"


Chest::Chest(ObjectData& data, AbstractAction * action) : InteractableObject(data)
{
	interactObj = action;
}

Chest::~Chest()
{
	
}

void Chest::interact()
{
	interactObj->run();
	setInteraction(new AbstractAction());
}
