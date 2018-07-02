#include "CardObject.h"
#include "InteractionObject.h"



CardObject::CardObject(Card * c, Vector2f position, Vector2f scale) : 
	InteractableObject(c->getName(), c->getTexture(), position, scale)
{
	card = c;
	setInteraction(new GiveCardAction(card));

	originalPosition = position;
	originalScale = scale;
}

CardObject::~CardObject()
{
}

bool CardObject::update(float dt)
{
	timer.update(dt);
	float f = timer.getTotalTime();

	offsetPos = Vector2f(0, 16*cos(f));
	offsetScale = Vector2f(sin(f*4), 1);


	pos = originalPosition + offsetPos;
	scale = originalScale * offsetScale;

	return InteractableObject::update(dt) && (interactionCount < 1);
}
