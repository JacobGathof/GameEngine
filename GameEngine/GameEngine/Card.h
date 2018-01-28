#pragma once

#include <string>

#include "LivingAi.h"

class Card
{
public:
	Card(std::string n, std::string desc, LivingAi * a);
	~Card();

	std::string name;
	std::string description;

	LivingAi * ai;

	int update(int delta_time);
	LivingAi * use();
	friend std::ostream& operator<<(std::ostream &os, Card &c);
};

