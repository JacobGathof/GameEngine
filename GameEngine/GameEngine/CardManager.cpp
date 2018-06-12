#include "CardManager.h"


void CardManager::init()
{
	typedef std::string s;
	addCard(CardType::FIREBALL,					new Card(s("Fireball"),		s("Fire"), TextureType::CARD_ACE, nullptr));
	addCard(CardType::ICECYCLE,					new Card(s("Icecycle"),		s("Fire"), TextureType::CARD_GHOST, nullptr));
	addCard(CardType::BOULDER,					new Card(s("Boulder"),		s("Fire"), TextureType::CARD_ACE, nullptr));
	addCard(CardType::DAWN,						new Card(s("Dawn"),			s("Fire"), TextureType::CARD_ACE, nullptr));
	addCard(CardType::EXCALIBUR,				new Card(s("Excalibur"),	s("Fire"), TextureType::CARD_ACE, nullptr));
	addCard(CardType::LIGHTNING,				new Card(s("Lightning"),	s("Fire"), TextureType::CARD_ACE, nullptr));
	addCard(CardType::MOONLIGHT,				new Card(s("Moonlight"),	s("Fire"), TextureType::CARD_ACE, nullptr));
	addCard(CardType::PLANE_WALK,				new Card(s("Plane Walk"),	s("Fire"), TextureType::CARD_GHOST, nullptr));
	addCard(CardType::SHADOW_STEP,				new Card(s("Shadow Step"),	s("Fire"), TextureType::CARD_ACE, nullptr));
	addCard(CardType::SHOCK,					new Card(s("Shock"),		s("Fire"), TextureType::CARD_ACE, nullptr));
	addCard(CardType::STORM,					new Card(s("Storm"),		s("Fire"), TextureType::CARD_ACE, nullptr));
	addCard(CardType::TRANSMISSION,				new Card(s("Transmission"), s("Fire"), TextureType::CARD_ACE, nullptr));
	addCard(CardType::TWILIGHT,					new Card(s("Twilight"),		s("Fire"), TextureType::CARD_ACE, nullptr));
	addCard(CardType::UNLIMITED_WATERWORKS,		new Card(s("Unlimited Waterworks"), s("Fire"), TextureType::CARD_ACE, nullptr));
}

void CardManager::addCard(CardType name, Card * card)
{
	elements[name] = card;
}
