#pragma once
#include "AbstractAction.h"
#include "Condition.h"

class WaitForAction : public AbstractAction
{
public:
	WaitForAction(Condition* cond);
	~WaitForAction();

	virtual int run(float dt);

private:
	Condition* cond;
};

