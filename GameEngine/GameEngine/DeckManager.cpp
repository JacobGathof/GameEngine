#include "DeckManager.h"

std::map<Decks, Deck *> DeckManager::decks;

DeckManager::DeckManager()
{
}


DeckManager::~DeckManager()
{
	for (auto pair : decks) {
		delete pair.second;
	}
}

void DeckManager::init()
{
	List<Card *> testCards;
	testCards.add(CardManager::get(CardType::BOULDER));
	testCards.add(CardManager::get(CardType::DAWN));
	testCards.add(CardManager::get(CardType::EXCALIBUR));
	testCards.add(CardManager::get(CardType::FIREBALL));
	testCards.add(CardManager::get(CardType::ICECYCLE));
	testCards.add(CardManager::get(CardType::LIGHTNING));
	testCards.add(CardManager::get(CardType::MOONLIGHT));
	testCards.add(CardManager::get(CardType::PLANE_WALK));
	testCards.add(CardManager::get(CardType::SHADOW_STEP));
	testCards.add(CardManager::get(CardType::SHOCK));
	testCards.add(CardManager::get(CardType::TRANSMISSION));
	testCards.add(CardManager::get(CardType::TWILIGHT));
	testCards.add(CardManager::get(CardType::UNLIMITED_WATERWORKS));
	addDeck(Decks::TEST, new Deck("Test", testCards));
}

Deck * DeckManager::getDeck(Decks deck)
{
	return decks.at(deck);
}

void DeckManager::clean()
{
}

void DeckManager::addDeck(Decks d, Deck * deck)
{
	decks[d] = deck;
}
