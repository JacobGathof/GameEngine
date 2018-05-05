#pragma once
#include "Card.h"


enum class Cards {
	FIREBALL,
	ICECYCLE,
	UNLIMITED_WATERWORKS,
	SHOCK,
	LIGHTNING,
	STORM,
	SHADOW_STEP,
	PLANE_WALK,
	TRANSMISSION,
	MOONLIGHT,
	TWILIGHT,
	DAWN,
	EXCALIBUR,
	BOULDER
};

class CardManager
{
public:
	CardManager();
	~CardManager();

	static void init();
	static Card * getCard(Cards name);

private:
	static std::map<Cards, Card *> dictionary;

	static void addCard(Cards name, Card * card);
};
