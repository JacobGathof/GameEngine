#include "Effect.h"

Effect::Effect(){}
Effect::~Effect(){}

void Effect::setActive(bool b)
{
	active = b;
}

void Effect::setParent(Object * o){
	parent = o;
}

