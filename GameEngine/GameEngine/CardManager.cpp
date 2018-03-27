#include "CardManager.h"



void CardManager::init()
{
	addCard(CardType::CARD_FIREBALL);
}

void CardManager::addCard(CardType ct)
{
	elements[ct] = new Card("Test", "Test", 0);
}
