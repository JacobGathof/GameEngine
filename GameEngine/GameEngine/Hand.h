#pragma once

#include <vector>
#include "Card.h"
#include "List.h"

#define DEFAULT_HAND_SIZE 5

class Hand
{
public:
	Hand();
	~Hand();

	List<Card> hand;
	int maxSize = DEFAULT_HAND_SIZE;

	void increaseHandSize(int i);
	void setHandSize(int i);
	Card getCard(int i);
	Card removeCard(int i);
	bool addCard(Card &card);
	
};

