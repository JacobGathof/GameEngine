#pragma once

#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(std::string n, std::string desc);
	~Weapon();
};

