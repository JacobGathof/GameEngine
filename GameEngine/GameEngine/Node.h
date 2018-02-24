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

	void addAction(AbstractScriptAction* act);
	void setActions(List<AbstractScriptAction*> act);

	void addEdge(Edge* edge);
	void setEdges(List<Edge*> edges);

private:
	List<AbstractScriptAction*> actions;
	List<Edge*> conditions;
	int actionPtr = 0;

	bool completedAllActions;
};

