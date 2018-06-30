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

	void pauseNode();
	void unpauseNode();

	int status = 1;

private:
	List<AbstractAction*> actions;
	List<Edge*> conditions;
	int actionPtr = 0;

	bool completedAllActions;
};

