#include "Edge.h"
#include "Node.h"

Edge::Edge(Condition * c, Node * n)
{
	condition = c;
	node = n;
}

Edge::~Edge()
{
	delete condition;
}
