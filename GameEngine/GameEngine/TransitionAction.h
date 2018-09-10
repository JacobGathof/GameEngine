#pragma once
#include "AbstractAction.h"
#include <string>

class TransitionAction : public AbstractAction
{
public:
	TransitionAction(std::string dest);
	~TransitionAction();
	virtual int run(float dt = 0.0f);

private:
	std::string destination;
};

