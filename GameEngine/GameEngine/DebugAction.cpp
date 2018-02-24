#include "DebugAction.h"
#include <iostream>



DebugAction::DebugAction(char * str)
{
	msg = str;
}

DebugAction::~DebugAction()
{
}

int DebugAction::run(float dt)
{
	std::cout << msg << std::endl;
	return 1;
}
