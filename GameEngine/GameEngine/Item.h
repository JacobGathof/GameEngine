#pragma once

#include "TextureManager.h"
#include <string>

class Item
{
public:
	Item(std::string n, std::string desc);
	~Item();

	virtual void setTexture(TextureType t);
	virtual void setName(std::string n);
	virtual void setDescription(std::string desc);
	virtual std::string getName();
	virtual std::string getDescription();
	virtual TextureType getTexture();

private:
	std::string name;
	std::string description;
	TextureType texture;
};

