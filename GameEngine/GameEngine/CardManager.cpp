#include "CardManager.h"


void CardManager::init()
{
	addCard(CardType::FIREBALL, new Card("Fireball", "Fire", TextureType::CARD_ACE, nullptr));
	addCard(CardType::ICECYCLE, new Card("Icecycle", "Fire", TextureType::CARD_GHOST, nullptr));
	addCard(CardType::BOULDER, new Card("Boulder", "Fire", nullptr));
	addCard(CardType::DAWN, new Card("Dawn", "Fire", nullptr));
	addCard(CardType::EXCALIBUR, new Card("Excalibur", "Fire", nullptr));
	addCard(CardType::LIGHTNING, new Card("Lightning", "Fire", nullptr));
	addCard(CardType::MOONLIGHT, new Card("Moonlight", "Fire", nullptr));
	addCard(CardType::PLANE_WALK, new Card("Plane Walk", "Fire", TextureType::CARD_GHOST, nullptr));
	addCard(CardType::SHADOW_STEP, new Card("Shadow Step", "Fire", nullptr));
	addCard(CardType::SHOCK, new Card("Shock", "Fire", nullptr));
	addCard(CardType::STORM, new Card("Storm", "Fire", nullptr));
	addCard(CardType::TRANSMISSION, new Card("Transmission", "Fire", nullptr));
	addCard(CardType::TWILIGHT, new Card("Twilight", "Fire", nullptr));
	addCard(CardType::UNLIMITED_WATERWORKS, new Card("Unlimited Waterworks", "Fire", nullptr));
}

void CardManager::addCard(CardType name, Card * card)
{
	elements[name] = card;
}
