#include "CardObject.h"
#include "InteractionObject.h"



CardObject::CardObject(ObjectData& data, Card * c) : InteractableObject(data)
{
	card = c;
	setInteraction(new GiveCardAction(card));

	originalPosition = pos;
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
