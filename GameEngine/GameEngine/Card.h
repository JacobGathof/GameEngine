#pragma once

#include <string>
#include "Item.h"


class LivingAi;

class Card : public Item
{
public:
	Card(std::string& n, std::string& desc, TextureType tex, LivingAi * a);
	~Card();

	LivingAi * ai;

	int update(float dt);
	LivingAi * use();
	friend std::ostream& operator<<(std::ostream &os, Card &c);
};

