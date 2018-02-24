#pragma once
#include "AbstractScriptAction.h"

class DebugAction : public AbstractScriptAction
{
public:
	DebugAction(char* str);
	~DebugAction();
	virtual int run(float dt);
private:
	char* msg;
};

