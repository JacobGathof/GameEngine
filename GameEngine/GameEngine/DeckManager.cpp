#include "DeckManager.h"
#include "ResourceManager.h"


void DeckManager::init()
{
	List<Card *> testCards;
	testCards.add(Res::get(CardType::BOULDER));
	testCards.add(Res::get(CardType::DAWN));
	testCards.add(Res::get(CardType::EXCALIBUR));
	testCards.add(Res::get(CardType::FIREBALL));
	testCards.add(Res::get(CardType::ICECYCLE));
	testCards.add(Res::get(CardType::LIGHTNING));
	testCards.add(Res::get(CardType::MOONLIGHT));
	testCards.add(Res::get(CardType::PLANE_WALK));
	testCards.add(Res::get(CardType::SHADOW_STEP));
	testCards.add(Res::get(CardType::SHOCK));
	testCards.add(Res::get(CardType::TRANSMISSION));
	testCards.add(Res::get(CardType::TWILIGHT));
	testCards.add(Res::get(CardType::UNLIMITED_WATERWORKS));
	addDeck(DeckType::TEST, new Deck("Test", testCards));
}


void DeckManager::addDeck(DeckType d, Deck * deck)
{
	elements[d] = deck;
}
