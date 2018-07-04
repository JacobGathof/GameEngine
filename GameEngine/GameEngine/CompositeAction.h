#pragma once
#include "AbstractAction.h"
#include "List.h"

class CompositeAction : public AbstractAction
{
public:
	CompositeAction(std::initializer_list<AbstractAction*> act);
	~CompositeAction();
	virtual int run(float dt);
private:
	List<AbstractAction*> actions;
	int pointer;
};

