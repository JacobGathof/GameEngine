#include "WeaponManager.h"



void WeaponManager::init()
{
	addWeapon(WeaponType::SWORD, new Weapon(std::string("Sword"), TextureType::TEXTURE_DAGON, std::string("A Basic Iron Sword")));
	addWeapon(WeaponType::BOW, new Weapon(std::string("Bow"), TextureType::TEXTURE_MAVIS, std::string("Bow and Arrow")));
}

void WeaponManager::addWeapon(WeaponType name, Weapon * weapon)
{
	elements[name] = weapon;
}
