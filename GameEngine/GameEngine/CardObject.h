#pragma once
#include "InteractableObject.h"
#include "Card.h"

class CardObject : public InteractableObject
{
public:
	CardObject(ObjectData& data, Card* c);
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

