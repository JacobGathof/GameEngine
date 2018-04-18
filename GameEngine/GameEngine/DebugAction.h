#pragma once
#include "AbstractAction.h"

class DebugAction : public AbstractAction
{
public:
	DebugAction(char* str);
	~DebugAction();
	virtual int run(float dt);
private:
	char* msg;
};

