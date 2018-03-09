#pragma once
#include "AbstractScriptAction.h"
#include "UIManager.h"

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

