#pragma once
#include "AbstractAction.h"

class TransitionAction : public AbstractAction
{
public:
	TransitionAction();
	~TransitionAction();
	virtual int run(float dt = 0.0f);

private:

};

