#pragma once
#include "Card.h"


enum class CardType {
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
	static Card * get(CardType name);
	static void clean();

private:
	static std::map<CardType, Card *> dictionary;

	static void addCard(CardType name, Card * card);
};
