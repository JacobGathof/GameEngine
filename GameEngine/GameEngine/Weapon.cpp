#include "Weapon.h"


Weapon::Weapon(std::string n, std::string desc) : Item(n, desc)
{
	type = ItemType::WEAPON;
}

Weapon::~Weapon()
{
}
