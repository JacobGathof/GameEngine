#include "Condition.h"
#include "GameState.h"
#include  <iostream>

Condition::Condition()
{
}

bool Condition::evaluate()
{
	return false;
}





ChoiceCondition::ChoiceCondition(int a1, bool m)
{
	arg1 = a1;
	match = m;
}

bool ChoiceCondition::evaluate()
{
	return !(match ^ (GameState::choicePointer == arg1));
}



IntCondition::IntCondition(int a1, int a2)
{
	arg1 = a1;
	arg2 = a2;
}

bool IntCondition::evaluate()
{
	return arg1 == arg2;
}
