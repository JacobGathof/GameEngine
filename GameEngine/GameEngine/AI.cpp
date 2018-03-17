#include "AI.h"



AI::AI()
{
}


AI::~AI()
{
}

bool AI::execute(Object * obj, float dt)
{
	return false;
}

bool AI::execute(AnimatedObject * obj, float dt)
{
	return false;
}

bool AI::execute(MovableObject * obj, float dt)
{
	return false;
}

bool AI::execute(LivingObject * obj, float dt)
{
	return false;
}
