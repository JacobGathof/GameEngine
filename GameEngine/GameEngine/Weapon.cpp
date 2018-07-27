#include "Weapon.h"
#include "Inventory.h"

Weapon::Weapon(std::string& n, TextureType tex, std::string& desc) : Item(n, tex, desc)
{
}

Weapon::~Weapon()
{
}

void Weapon::addToInventory(Inventory * inv)
{
	inv->add(this);
}
