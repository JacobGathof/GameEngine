#include "Card.h"


Card::Card(std::string n, std::string desc, LivingAi * a) : Item(n, desc)
{
	ai = a;
}

Card::~Card()
{
}

int Card::update(int delta_time)
{
	//Might be necessary for cards that have effects in hand.  Don't know

	return 0;
}

LivingAi * Card::use()
{
	return ai;
}

std::ostream & operator<<(std::ostream & os, Card & c)
{
	return os << c.getName() << ":/n" << c.getDescription();
}
