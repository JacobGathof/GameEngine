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

void Inventory::add(Card * wep)
{
	items.at(ItemType::CARD).add(wep);
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

List<TextureType>& Inventory::getAllTextures(ItemType type)
{
	List<TextureType> textures;
	List<Item *> itemList = items.at(type);
	for (Item * item : itemList) {
		textures.add(item->getTexture());
	}
	return textures;
}
