#include "CompositeAction.h"
#include "GlobalActionInvoker.h"


CompositeAction::CompositeAction(std::initializer_list<AbstractAction*> act)
{
	actions = act;
}

CompositeAction::~CompositeAction()
{
	if (!sentList) {
		for (auto a : actions) {
			delete a;
		}
	}
}

int CompositeAction::run(float dt)
{
	sentList = true;
	GlobalActionInvoker::addActionSet(actions);
	return 1;
}
