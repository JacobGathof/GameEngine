#include "CardManager.h"

std::map<Cards, Card *> CardManager::dictionary;

CardManager::CardManager()
{
}


CardManager::~CardManager()
{
	for (auto pair : dictionary) {
		delete pair.second;
	}
}

void CardManager::init()
{
	addCard(Cards::FIREBALL, new Card("Fireball", "Fire", nullptr));
	addCard(Cards::ICECYCLE, new Card("Icecycle", "Fire", nullptr));
	addCard(Cards::BOULDER, new Card("Boulder", "Fire", nullptr));
	addCard(Cards::DAWN, new Card("Dawn", "Fire", nullptr));
	addCard(Cards::EXCALIBUR, new Card("Excalibur", "Fire", nullptr));
	addCard(Cards::LIGHTNING, new Card("Lightning", "Fire", nullptr));
	addCard(Cards::MOONLIGHT, new Card("Moonlight", "Fire", nullptr));
	addCard(Cards::PLANE_WALK, new Card("Plane Walk", "Fire", nullptr));
	addCard(Cards::SHADOW_STEP, new Card("Shadow Step", "Fire", nullptr));
	addCard(Cards::SHOCK, new Card("Shock", "Fire", nullptr));
	addCard(Cards::STORM, new Card("Storm", "Fire", nullptr));
	addCard(Cards::TRANSMISSION, new Card("Transmission", "Fire", nullptr));
	addCard(Cards::TWILIGHT, new Card("Twilight", "Fire", nullptr));
	addCard(Cards::UNLIMITED_WATERWORKS, new Card("Unlimited Waterworks", "Fire", nullptr));
}

Card * CardManager::getCard(Cards name)
{
	return dictionary.at(name);
}

void CardManager::addCard(Cards name, Card * card)
{
	dictionary[name] = card;
}
