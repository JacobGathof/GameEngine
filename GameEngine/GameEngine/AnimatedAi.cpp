#include "AnimatedAi.h"

#include "AnimatedObject.h"

AnimatedAi::AnimatedAi()
{
}


AnimatedAi::~AnimatedAi()
{
}

bool AnimatedAi::execute(void * o)
{
	AnimatedObject * obj = (AnimatedObject *)o;
	return false;
}
