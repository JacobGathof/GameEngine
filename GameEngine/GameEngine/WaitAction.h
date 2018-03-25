#pragma once
#include "AbstractScriptAction.h"
#include "Timer.h"

class WaitAction : public AbstractScriptAction
{
public:
	WaitAction(float time);
	~WaitAction();
	virtual int run(float dt);
	virtual void reset();

private:
	Timer timer;

};

