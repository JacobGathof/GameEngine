#pragma once

#include <string>

#include "LivingAi.h"
#include "Item.h"

class Card : public Item
{
public:
	Card(std::string n, std::string desc, LivingAi * a);
	Card(std::string n, std::string desc, TextureType tex, LivingAi * a);
	~Card();

	LivingAi * ai;

	int update(int delta_time);
	LivingAi * use();
	friend std::ostream& operator<<(std::ostream &os, Card &c);
};

