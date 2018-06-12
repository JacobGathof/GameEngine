#include "Chest.h"


Chest::Chest(TextureType t, Vector2f & position, Vector2f & sc, AbstractAction * action) 
	: Object(std::string("Chest"), t, position, sc)
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
