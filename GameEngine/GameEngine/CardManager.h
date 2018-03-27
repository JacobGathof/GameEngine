#pragma once
#include "IManager.h"
#include "Card.h"
#include "ResourceType.h"

class CardManager : public IManager<Card, CardType>
{
public:
	virtual void init();
private:
	void addCard(CardType ct);
};

