#pragma once
#include "ResourceType.h"
#include "IManager.h"
#include "Armor.h"

class ArmorManager : public IManager<Armor, ArmorType>
{
public:
	virtual void init();

private:

	void addArmor(ArmorType name, Armor * armor);
};

