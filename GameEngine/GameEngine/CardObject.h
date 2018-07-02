#pragma once
#include "InteractableObject.h"
#include "Card.h"

class CardObject : public InteractableObject
{
public:
	CardObject(Card* c, Vector2f position, Vector2f scale);
	~CardObject();

	virtual bool update(float dt);

private:
	Card * card;
	Vector2f originalPosition;
	Vector2f originalScale;

	Vector2f offsetPos;
	Vector2f offsetScale;

	Timer timer;
};

