#include "Deck.h"



Deck::Deck()
{
	name = "default";
}

Deck::Deck(std::string n, std::vector<Card> cards)
{
	name = n;
	deck = cards;
}


Deck::~Deck()
{
}

void Deck::shuffle()
{
	std::random_shuffle(deck.begin(), deck.end());
}

void Deck::addCard(Card &card)
{
	deck.push_back(card);
}

void Deck::addAll(std::vector<Card> cards)
{
	for (Card c : cards) {
		deck.push_back(c);
	}
}

Card& Deck::draw()
{
	Card c = deck[0];
	deck.erase(deck.begin());
	return c;
}

void Deck::removeCard(int index)
{
	deck.erase(deck.begin() + index);
}

void Deck::reset()
{
	for (Card c : discard) {
		deck.push_back(c);
	}
	for (int i = 0; i < discard.size(); i++) {
		discard.erase(discard.begin());
	}
	shuffle();
}

void Deck::rename(std::string n)
{
	name = n;
}

void Deck::discardCard(Card & card)
{
	discard.push_back(card);
}

