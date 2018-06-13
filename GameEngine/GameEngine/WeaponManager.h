#pragma once
#include "ResourceType.h"
#include "IManager.h"
#include "Weapon.h"

class WeaponManager : public IManager<Weapon, WeaponType>
{
public:
	virtual void init();

private:

	void addWeapon(WeaponType name, Weapon * weapon);
};

