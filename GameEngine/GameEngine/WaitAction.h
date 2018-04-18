#pragma once
#include "AbstractAction.h"
#include "Timer.h"

class WaitAction : public AbstractAction
{
public:
	WaitAction(float time);
	~WaitAction();
	virtual int run(float dt);
	virtual void reset();

private:
	Timer timer;

};

