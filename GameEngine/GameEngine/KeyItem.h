#pragma once

#include "Item.h"

class KeyItem : public Item
{
public:
	KeyItem(std::string& n, TextureType tex, std::string& desc);
	~KeyItem();
};

