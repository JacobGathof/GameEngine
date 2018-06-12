#pragma once

#include "Item.h"

class Armor : public Item
{
public:
	Armor(std::string& n, TextureType tex, std::string& desc);
	~Armor();
};

