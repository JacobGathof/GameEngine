#include "Item.h"


Item::Item(std::string n, std::string desc)
{
	name = n;
	description = desc;
}

Item::~Item()
{
}

void Item::setTexture(TextureType t)
{
	texture = t;
}

void Item::setName(std::string n)
{
	name = n;
}

void Item::setDescription(std::string desc)
{
	description = desc;
}

std::string Item::getName()
{
	return name;
}

std::string Item::getDescription()
{
	return description;
}

TextureType Item::getTexture()
{
	return texture;
}
