#include "Inventory.h"



Inventory::Inventory()
{
	
}


Inventory::~Inventory()
{
}

void Inventory::add(Weapon * w)
{
	weapons.add(w);
}

void Inventory::add(Armor * a)
{
	armors.add(a);
}

void Inventory::add(KeyItem * k)
{
	keyItems.add(k);
}

void Inventory::add(Card * c)
{
	cards.add(c);
}


List<Card*>& Inventory::getCards()
{
	return cards;
}

List<Weapon*>& Inventory::getWeapons()
{
	return weapons;
}

List<Armor*>& Inventory::getArmor()
{
	return armors;
}

List<KeyItem*>& Inventory::getKeyItems()
{
	return keyItems;
}

void Inventory::printInventory()
{
	std::cout << "Inventory" << std::endl;
	std::cout << "Armor" << std::endl;
	for (Item * it : armors) {
		std::cout << it->getName() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Weapons" << std::endl;
	for (Item * it : weapons) {
		std::cout << it->getName() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Key Items" << std::endl;
	for (Item * it : keyItems) {
		std::cout << it->getName() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Card" << std::endl;
	for (Item * it : cards) {
		std::cout << it->getName() << std::endl;
	}
	std::cout << "--------------------------------\n" << std::endl;
}

void Inventory::printCurrentInventory()
{
	std::cout << "Equipped:" << std::endl;
	std::cout << "Armor" << std::endl;
	if(current.armor != 0)
		std::cout << current.armor->getName() << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Weapons" << std::endl;
	if (current.weapon != 0)
		std::cout << current.weapon->getName() << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Card" << std::endl;
	for (auto it : current.deck) {
		std::cout << it->getName() << std::endl;
	}
	std::cout << "--------------------------------\n" << std::endl;
}


void Inventory::addCardToCurrentDeck(Card * card){
	current.deck.add(card);
}

void Inventory::removeCardFromCurrentDeck(Card * card){
	current.deck.remove(card);
}

void Inventory::setCurrentWeapon(Weapon * w){
	current.weapon = w;
}

void Inventory::setCurrentArmor(Armor * armor){
	current.armor = armor;
}

Weapon * Inventory::getCurrentWeapon(){
	return current.weapon;
}

Armor * Inventory::getCurrentArmor(){
	return current.armor;
}

List<Card*>& Inventory::getCurrentDeck(){
	return current.deck;
}


