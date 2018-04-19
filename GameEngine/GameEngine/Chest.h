#pragma once

#include "Object.h"
#include "Item.h"
#include "InteractionObject.h"

class Chest : public Object
{
public:
	Chest(std::string n, TextureType t, Vector2f position, Vector2f sc);
	Chest(std::string n, TextureType t, Vector2f position, Vector2f sc, List<Item *> it);
	~Chest();

	List<Item *> items;

	void addItem(Item * item);
	List<Item *>& giveItems();
	Item * giveItem(int i);
};

