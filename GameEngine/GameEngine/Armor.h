#pragma once

#include "Item.h"

class Armor : public Item
{
public:
	Armor(std::string n, std::string desc);
	~Armor();
};

