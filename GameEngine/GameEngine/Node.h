#pragma once
#include "List.h"
#include "AbstractAction.h"
#include "Edge.h"

#define NODE_RUNNING 0
#define NODE_HALTED 1
#define NODE_TERMINATED 2


class Node
{
public:
	Node();
	~Node();

	Node* update(float dt);
	Node* getNextNode();
	void resetNode();
	int checkAction(float dt);

	void addAction(AbstractAction* act);
	void setActions(List<AbstractAction*> act);

	void addEdge(Edge* edge);
	void setEdges(List<Edge*> edges);

	int status = NODE_RUNNING;

private:
	List<AbstractAction*> actions;
	List<Edge*> conditions;
	AbstractAction* checkActionPtr;

	int actionPtr = 0;

	bool completedAllActions;
};

