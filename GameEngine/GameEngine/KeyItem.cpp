#include "KeyItem.h"
#include "Inventory.h"

KeyItem::KeyItem(std::string& n, TextureType tex, std::string& desc) : Item(n, tex, desc){

}

KeyItem::KeyItem(ItemData & data) : Item(data) {

}

KeyItem::~KeyItem()
{
}

void KeyItem::addToInventory(Inventory * inv)
{
	inv->add(this);
}
