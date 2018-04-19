#include "Chest.h"


Chest::Chest(std::string n, TextureType t, Vector2f position, Vector2f sc) : Object(n,t,position, sc)
{
	interactObj = new GiveItemAction();
}

Chest::Chest(std::string n, TextureType t, Vector2f position, Vector2f sc, List<Item *> it) : Object(n, t, position, sc)
{
	items = it;
	interactObj = new GiveItemAction();
	for (Item * i : it) {
		((GiveItemAction *)interactObj)->addItem(i);
	}
}

Chest::~Chest()
{
	for (auto i : items) {
		if (i != nullptr) {
			delete i;
		}
	}
}

void Chest::addItem(Item * item)
{
	((GiveItemAction *)interactObj)->addItem(item);
	items.add(item);
}

List<Item*>& Chest::giveItems()
{
	return items;
}

Item * Chest::giveItem(int i)
{
	return items.get(i);
}
