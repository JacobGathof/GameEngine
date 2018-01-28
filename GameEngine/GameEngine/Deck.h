#pragma once

#define MAX_SIZE 60
#define MIN_SIZE 0

#include <vector>
#include <string.h>
#include <random>
#include "Card.h"

class Deck
{
public:
	Deck();
	Deck(std::string n, std::vector<Card> cards);
	~Deck();

	std::string name;
	std::vector<Card> deck;
	std::vector<Card> discard;

	void shuffle();
	void addCard(Card &card);
	void addAll(std::vector<Card> cards);
	Card &draw();
	void removeCard(int index);
	void reset();
	void rename(std::string n);
	void discardCard(Card &card);
};

