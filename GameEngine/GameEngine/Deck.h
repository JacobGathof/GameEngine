#pragma once

#define MAX_SIZE 60
#define MIN_SIZE 0

#include <vector>
#include <string.h>
#include <random>
#include "Card.h"
#include "List.h"

class Deck
{
public:
	Deck();
	Deck(std::string n, List<Card> cards);
	~Deck();

	std::string name;
	

	void shuffle();
	void addCard(Card &card);
	void addAll(List<Card> cards);
	Card draw();
	void removeCard(int index);
	void reset();
	void rename(std::string n);
	void discardCard(Card &card);

private:
	List<Card> deck;
	List<Card> discard;
};

