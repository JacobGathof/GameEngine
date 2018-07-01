#include "CardObject.h"
#include "InteractionObject.h"



CardObject::CardObject(Card * c, Vector2f position, Vector2f scale) : 
	InteractableObject(c->getName(), c->getTexture(), position, scale)
{
	card = c;
	setInteraction(new GiveCardAction(card));
}

CardObject::~CardObject()
{
}

bool CardObject::update(float dt)
{
	return InteractableObject::update(dt) && (interactionCount < 1);
}
