#include "Deck.h"



Deck::Deck()
{
	name = "default";
}

Deck::Deck(std::string n, List<Card *> cards)
{
	name = n;
	deck.addAll(cards);
}


Deck::~Deck()
{
}

void Deck::shuffle()
{
	std::random_shuffle(deck.begin(), deck.end());
}

void Deck::addCard(Card * card)
{
	deck.add(card);
}

void Deck::addAll(List<Card *> cards)
{
	deck.addAll(cards);
}

Card * Deck::draw()
{
	if (deck.size() <= 0) {
		std::cout << "Deck Out" << std::endl;
		return nullptr;
	}
	Card * c = deck[0];
	discardCard(c);
	deck.removeIndex(0);
	return c;
}

void Deck::removeCard(int index)
{
	deck.removeIndex(index);
}

void Deck::reset()
{
	for (Card * c : discard) {
		deck.add(c);
	}
	for (int i = 0; i < discard.size(); i++) {
		discard.removeIndex(0);
	}
	shuffle();
}

void Deck::rename(std::string n)
{
	name = n;
}

void Deck::discardCard(Card * card)
{
	discard.add(card);
}

