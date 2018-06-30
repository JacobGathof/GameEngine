#pragma once
#include "AbstractAction.h"

class PauseAction : public AbstractAction
{
public:
	PauseAction();
	~PauseAction();
	virtual int run(float dt = 0.0f);
private:
};
