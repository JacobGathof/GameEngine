#pragma once

#include <string>
#include "Item.h"


class AI;

class Card : public Item
{
public:
	Card(std::string& n, std::string& desc, TextureType tex, AI * a);
	~Card();

	AI * ai;

	int update(float dt);

	virtual void addToInventory(Inventory* inv);

	AI * use();
	friend std::ostream& operator<<(std::ostream &os, Card &c);
};

