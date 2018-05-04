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

Card Hand::getCard(int i)
{
	return hand[i];
}

Card Hand::removeCard(int i)
{
	if (i >= hand.size()) {
		return hand[hand.size() - 1];
	}
	Card &c = hand[i];
	hand.removeIndex(i);
	return c;
}

bool Hand::addCard(Card & card)
{
	if (hand.size() >= maxSize) {
		return false;
	}
	hand.add(card);
	return true;
}

