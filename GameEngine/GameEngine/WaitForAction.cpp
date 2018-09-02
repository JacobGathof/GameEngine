#include "WaitForAction.h"



WaitForAction::WaitForAction(Condition * c)
{
	cond = c;
}

WaitForAction::~WaitForAction()
{
	delete cond;
}

int WaitForAction::run(float dt)
{
	if (cond->evaluate()) {
		return ACTION_COMPLETE;
	}

	return ACTION_PAUSE;
}
