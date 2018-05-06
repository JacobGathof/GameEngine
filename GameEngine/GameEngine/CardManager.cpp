#include "CardManager.h"

std::map<CardType, Card *> CardManager::dictionary;

CardManager::CardManager()
{
}


CardManager::~CardManager()
{
	
}

void CardManager::init()
{
	addCard(CardType::FIREBALL, new Card("Fireball", "Fire", nullptr));
	addCard(CardType::ICECYCLE, new Card("Icecycle", "Fire", nullptr));
	addCard(CardType::BOULDER, new Card("Boulder", "Fire", nullptr));
	addCard(CardType::DAWN, new Card("Dawn", "Fire", nullptr));
	addCard(CardType::EXCALIBUR, new Card("Excalibur", "Fire", nullptr));
	addCard(CardType::LIGHTNING, new Card("Lightning", "Fire", nullptr));
	addCard(CardType::MOONLIGHT, new Card("Moonlight", "Fire", nullptr));
	addCard(CardType::PLANE_WALK, new Card("Plane Walk", "Fire", nullptr));
	addCard(CardType::SHADOW_STEP, new Card("Shadow Step", "Fire", nullptr));
	addCard(CardType::SHOCK, new Card("Shock", "Fire", nullptr));
	addCard(CardType::STORM, new Card("Storm", "Fire", nullptr));
	addCard(CardType::TRANSMISSION, new Card("Transmission", "Fire", nullptr));
	addCard(CardType::TWILIGHT, new Card("Twilight", "Fire", nullptr));
	addCard(CardType::UNLIMITED_WATERWORKS, new Card("Unlimited Waterworks", "Fire", nullptr));
}

Card * CardManager::get(CardType name)
{
	return dictionary.at(name);
}

void CardManager::clean()
{
	for (auto pair : dictionary) {
		delete pair.second;
	}
}

void CardManager::addCard(CardType name, Card * card)
{
	dictionary[name] = card;
}
