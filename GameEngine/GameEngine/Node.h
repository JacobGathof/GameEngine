#pragma once
#include "List.h"
#include "AbstractAction.h"
#include "Edge.h"

class Node
{
public:
	Node();
	~Node();

	Node* update(float dt);
	Node* getNextNode();
	void resetNode();

	void addAction(AbstractAction* act);
	void setActions(List<AbstractAction*> act);

	void addEdge(Edge* edge);
	void setEdges(List<Edge*> edges);

private:
	List<AbstractAction*> actions;
	List<Edge*> conditions;
	int actionPtr = 0;

	bool completedAllActions;
};

