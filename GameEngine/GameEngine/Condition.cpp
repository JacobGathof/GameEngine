#include "Condition.h"


Condition::Condition(int a1, int a2)
{
	arg1 = a1;
	arg2 = a2;
}

Condition::~Condition()
{
}

bool Condition::evaluate()
{
	return arg1 == arg2;
}
