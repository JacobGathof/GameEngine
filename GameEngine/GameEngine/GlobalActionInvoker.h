#pragma once
#include <queue>
#include "AbstractAction.h"

class GlobalActionInvoker
{
public:
	static void init();
	static void clean();

	static void update(float dt);
	static void addAction(AbstractAction* act);


private:
	static std::queue<AbstractAction*> actionQueue;

};

