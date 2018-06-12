#include "Card.h"


Card::Card(std::string& n, std::string& desc, TextureType tex, LivingAi * a) : Item(n,tex,desc)
{
	ai = a;
}

Card::~Card()
{
}

int Card::update(float dt)
{
	//Might be necessary for cards that have effects in hand.  Don't know

	return 0;
}

LivingAi * Card::use()
{
	
	std::cout << "Using Card: " << this->getName() << std::endl;
	return ai;
}

std::ostream & operator<<(std::ostream & os, Card & c)
{
	return os << c.getName() << ":/n" << c.getDescription();
}
