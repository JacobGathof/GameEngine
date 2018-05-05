#include "DeckManager.h"

std::map<Decks, Deck *> DeckManager::decks;

DeckManager::DeckManager()
{
}


DeckManager::~DeckManager()
{
}

void DeckManager::init()
{
	List<Card *> testCards;
	testCards.add(CardManager::getCard(Cards::BOULDER));
	testCards.add(CardManager::getCard(Cards::DAWN));
	testCards.add(CardManager::getCard(Cards::EXCALIBUR));
	testCards.add(CardManager::getCard(Cards::FIREBALL));
	testCards.add(CardManager::getCard(Cards::ICECYCLE));
	testCards.add(CardManager::getCard(Cards::LIGHTNING));
	testCards.add(CardManager::getCard(Cards::MOONLIGHT));
	testCards.add(CardManager::getCard(Cards::PLANE_WALK));
	testCards.add(CardManager::getCard(Cards::SHADOW_STEP));
	testCards.add(CardManager::getCard(Cards::SHOCK));
	testCards.add(CardManager::getCard(Cards::TRANSMISSION));
	testCards.add(CardManager::getCard(Cards::TWILIGHT));
	testCards.add(CardManager::getCard(Cards::UNLIMITED_WATERWORKS));
	addDeck(Decks::TEST, new Deck("Test", testCards));
}

Deck * DeckManager::getDeck(Decks deck)
{
	return decks.at(deck);
}

void DeckManager::addDeck(Decks d, Deck * deck)
{
	decks[d] = deck;
}
