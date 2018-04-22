#include "Inventory.h"



Inventory::Inventory()
{
	items.insert(std::pair<ItemType, List<Item *>>(ItemType::ARMOR, List<Item *>()));
	items.insert(std::pair<ItemType, List<Item *>>(ItemType::WEAPON, List<Item *>()));
	items.insert(std::pair<ItemType, List<Item *>>(ItemType::CARD, List<Item *>()));
	items.insert(std::pair<ItemType, List<Item *>>(ItemType::KEYITEM, List<Item *>()));
}


Inventory::~Inventory()
{
}

void Inventory::add(Weapon * wep)
{
	items.at(ItemType::WEAPON).add(wep);
}

void Inventory::add(Armor * wep)
{
	items.at(ItemType::ARMOR).add(wep);
}

void Inventory::add(KeyItem * wep)
{
	items.at(ItemType::KEYITEM).add(wep);
}

void Inventory::add(Card * c)
{
	items.at(ItemType::CARD).add(c);
	cards.add(c);
	std::cout << cards.size() << std::endl;
}

void Inventory::add(Item * wep)
{
	items.at(wep->type).add(wep);
	std::cout << "Armor" << std::endl;
	for (Item * it : items.at(ItemType::ARMOR)) {
		std::cout << it->getName() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Weapons" << std::endl;
	for (Item * it : items.at(ItemType::WEAPON)) {
		std::cout << it->getName() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Key Items" << std::endl;
	for (Item * it : items.at(ItemType::KEYITEM)) {
		std::cout << it->getName() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Card" << std::endl;
	for (Item * it : items.at(ItemType::CARD)) {
		std::cout << it->getName() << std::endl;
	}
	std::cout << "--------------------------------" << std::endl;
}

Item * Inventory::get(int i, ItemType type)
{
	List<Item *> itemList = items.at(type);
	if (itemList.size() >= i) {
		return nullptr;
	}
	return itemList.get(i);
}

List<Item *>& Inventory::getAll(ItemType type)
{
	return items.at(type);
}

List<Card*>& Inventory::getCards()
{
	return cards;
}

List<TextureType> Inventory::getAllTextures(ItemType type)
{
	List<TextureType> textures;
	List<Item *> itemList = items.at(type);
	for (Item * item : itemList) {
		textures.add(item->getTexture());
	}
	return textures;
}
