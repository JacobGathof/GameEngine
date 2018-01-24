#include "LivingAi.h"
#include "LivingObject.h"


LivingAi::LivingAi()
{
}


LivingAi::~LivingAi()
{
}

bool LivingAi::execute(void * o)
{
	LivingObject * obj = (LivingObject *) o;
	return false;
}
