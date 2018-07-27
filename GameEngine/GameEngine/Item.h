#pragma once

#include "TextureManager.h"
#include <string>

class Inventory;

struct ItemData {
	std::string name;
	std::string description;
	TextureType tex;
};


class Item
{
public:
	virtual ~Item();

	virtual void setTexture(TextureType t);
	virtual void setName(std::string& n);
	virtual void setDescription(std::string& desc);
	virtual std::string& getName();
	virtual std::string& getDescription();
	virtual TextureType getTexture();

	virtual void addToInventory(Inventory* inv) = 0;

protected:
	Item(std::string& n, TextureType tex, std::string& desc);
	Item(ItemData& data);

private:
	std::string name;
	std::string description;
	TextureType texture;
};

