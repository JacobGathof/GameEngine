#pragma once

#include "CardManager.h"
#include "Deck.h"



class DeckManager : public IManager<Deck, DeckType>
{
public:
	virtual void init();

private:
	void addDeck(DeckType d, Deck * deck);
};

