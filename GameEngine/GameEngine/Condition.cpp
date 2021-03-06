#include "Condition.h"
#include "GameState.h"
#include  <iostream>

Condition::Condition()
{
}

bool Condition::evaluate()
{
	return true;
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

TextBoxCondition::TextBoxCondition(bool On)
{
	on = On;
}

bool TextBoxCondition::evaluate()
{
	return GameState::textboxEmpty != on;
}


FlagCondition::FlagCondition(std::string s, bool b)
{
	str = s;
	val = b;
}

bool FlagCondition::evaluate()
{
	return (GameState::flags[str] == val);
}



InteractCondition::InteractCondition(std::string nm)
{
	name = nm;
}

bool InteractCondition::evaluate()
{
	return GameState::applicationState.interactionName == name;
}
