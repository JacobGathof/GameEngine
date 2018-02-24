#include "Graph.h"



Graph::Graph()
{
	root = new Node();
	current = root;
}


Graph::~Graph()
{
	delete root;
}

void Graph::update(float dt)
{
	Node* n = current->update(dt);
	if (n != 0) {
		current = n;
	}
}
