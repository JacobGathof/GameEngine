#pragma once
#include "Card.h"
#include "IManager.h"
#include "ResourceType.h"


class CardManager : public IManager<Card, CardType>
{
public:
	virtual void init();

private:

	void addCard(CardType name, Card * card);
};
