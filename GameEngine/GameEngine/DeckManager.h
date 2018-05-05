#pragma once

#include "CardManager.h"
#include "Deck.h"


enum class Decks {
	TEST,
};

class DeckManager
{
public:
	DeckManager();
	~DeckManager();

	static void init();
	static Deck * getDeck(Decks deck);
	static void clean();

private:

	static std::map<Decks, Deck *> decks;
	static void addDeck(Decks d, Deck * deck);
};

