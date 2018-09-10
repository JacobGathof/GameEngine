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
	std::initializer_list<AbstractAction*> actions;
	bool sentList = false;
};

