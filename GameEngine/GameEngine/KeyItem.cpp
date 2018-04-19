#include "KeyItem.h"


KeyItem::KeyItem(std::string n, std::string desc) : Item(n, desc)
{
	type = ItemType::KEYITEM;
}

KeyItem::~KeyItem()
{
}
