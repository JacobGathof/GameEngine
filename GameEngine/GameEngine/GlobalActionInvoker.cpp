#include "GlobalActionInvoker.h"
#include "AbstractAction.h"

std::queue<AbstractAction*> GlobalActionInvoker::actionQueue;


void GlobalActionInvoker::init()
{
}

void GlobalActionInvoker::clean()
{
	while (!actionQueue.empty()) {
		auto a = actionQueue.front();
		actionQueue.pop();
		delete a;
	}
}

void GlobalActionInvoker::update(float dt)
{
	if (!actionQueue.empty()) {
		bool b = actionQueue.front()->run(dt);
		if (b) {
			actionQueue.pop();
		}
	}
}

void GlobalActionInvoker::addAction(AbstractAction * act)
{
	actionQueue.push(act);
}
