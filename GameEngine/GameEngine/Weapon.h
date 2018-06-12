#pragma once
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(std::string& n, TextureType tex, std::string& desc);
	~Weapon();
};

