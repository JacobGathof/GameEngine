#pragma once


#include "List.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "KeyItem.h"
#include "Card.h"
#include <map>


class Inventory
{
public:
	Inventory();
	~Inventory();

	std::map<ItemType, List<Item *>> items;


	void add(Weapon * wep);
	void add(Armor * wep);
	void add(KeyItem * wep);
	void add(Card * wep);
	void add(Item * wep);
	Item * get(int i, ItemType type);
	List<Item *>& getAll(ItemType type);
	List<Card *>& getCards();

	List<TextureType> getAllTextures(ItemType type);


private:
	List<Card*> cards;

};

