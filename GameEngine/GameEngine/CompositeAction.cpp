#include "CompositeAction.h"



CompositeAction::CompositeAction(std::initializer_list<AbstractAction*> act)
{
	actions = act;
	pointer = 0;
}

CompositeAction::~CompositeAction()
{
	for (auto a : actions) {
		delete a;
	}
}

int CompositeAction::run(float dt)
{
	AbstractAction* a = actions[pointer];
	if (a->run(dt)) {
		pointer++;
	}

	if (pointer >= actions.size()) {
		return 1;
	}

	return 0;
}
