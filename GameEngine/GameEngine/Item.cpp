#include "Item.h"
#include "Inventory.h"

Item::Item(std::string& n, TextureType tex, std::string& desc){
	name = n;
	description = desc;
	texture = tex;
}

Item::Item(ItemData & data){
	name = data.name;
	description = data.description;
	texture = data.tex;
}

Item::~Item(){}

void Item::setTexture(TextureType t){
	texture = t;
}

void Item::setName(std::string& n){
	name = n;
}

void Item::setDescription(std::string& desc){
	description = desc;
}

std::string& Item::getName(){
	return name;
}

std::string& Item::getDescription(){
	return description;
}

TextureType Item::getTexture(){
	return texture;
}
