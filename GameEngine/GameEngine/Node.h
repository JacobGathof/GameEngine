#pragma once
#include "List.h"
#include "AbstractScriptAction.h"
#include "Edge.h"

class Node
{
public:
	Node();
	~Node();

	Node* update(float dt);
	Node* getNextNode();
	void resetNode();

private:
	List<AbstractScriptAction*> actions;
	List<Edge*> conditions;
	int actionPtr = 0;

	bool completedAllActions;
};

