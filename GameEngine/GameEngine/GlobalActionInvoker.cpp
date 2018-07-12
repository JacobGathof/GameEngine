#include "GlobalActionInvoker.h"
#include "AbstractAction.h"

GlobalActionInvoker::ActionSet* GlobalActionInvoker::currentSet;
GlobalActionInvoker::ActionSet* GlobalActionInvoker::catchAllSet;
std::vector<GlobalActionInvoker::ActionSet*> GlobalActionInvoker::sets;



void GlobalActionInvoker::init()
{
	catchAllSet = new ActionSet();
}

void GlobalActionInvoker::clean()
{
	for (auto a : sets) {
		delete a;
	}
	delete catchAllSet;
}

void GlobalActionInvoker::update(float dt)
{
	for (int i = 0; i < sets.size(); i++) {
		auto a = sets[i];
		bool b = a->update(dt);
		if (b) {
			sets.erase(sets.begin()+(i--));
		}
	}
	catchAllSet->update(dt);
}

void GlobalActionInvoker::createActionSet()
{
	auto a = new ActionSet();
	sets.push_back(a);
	currentSet = a;
}

void GlobalActionInvoker::endActionSet()
{
	currentSet = catchAllSet;
}


void GlobalActionInvoker::addAction(AbstractAction * act)
{
	currentSet->addAction(act);
}


GlobalActionInvoker::ActionSet::~ActionSet()
{
	while (!actionQueue.empty()) {
		auto a = actionQueue.front();
		actionQueue.pop();
		delete a;
	}
}

void GlobalActionInvoker::ActionSet::addAction(AbstractAction * act)
{
	actionQueue.push(act);
}

bool GlobalActionInvoker::ActionSet::update(float dt)
{
	if (!actionQueue.empty()) {
		bool b = actionQueue.front()->run(dt);
		if (b) {
			actionQueue.pop();
		}
	}
	
	return actionQueue.empty();
}
