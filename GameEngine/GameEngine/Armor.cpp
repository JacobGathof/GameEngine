#include "Armor.h"


Armor::Armor(std::string n, std::string desc) : Item(n, desc)
{
	type = ItemType::ARMOR;
}

Armor::~Armor()
{
}
