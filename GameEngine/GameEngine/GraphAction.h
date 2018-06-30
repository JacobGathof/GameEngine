#pragma once
#include "AbstractAction.h"
#include "Graph.h"

class GraphAction : public AbstractAction
{
public:
	GraphAction(char* filename);
	~GraphAction();

	virtual int run(float dt);

private:
	Graph * graph;

};

