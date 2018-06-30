#include "GraphAction.h"



GraphAction::GraphAction(char * filename)
{
	graph = new Graph(filename);
}

GraphAction::~GraphAction()
{
	delete graph;
}

int GraphAction::run(float dt)
{
	return graph->update(dt);
}
