#include "Hand.h"



Hand::Hand()
{
}


Hand::~Hand()
{
}

void Hand::increaseHandSize(int i)
{
	maxSize += i;
}

void Hand::setHandSize(int i)
{
	maxSize = i;
}

Card &Hand::getCard(int i)
{
	return hand[i];
}

Card & Hand::removeCard(int i)
{
	Card &c = hand[i];
	hand.erase(hand.begin() + i);
	return c;
}

bool Hand::addCard(Card & card)
{
	if (hand.size() != maxSize) {
		return false;
	}
	hand.push_back(card);
	return true;
}
