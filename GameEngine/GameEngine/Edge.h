#pragma once
#include "Condition.h"

class Node;

class Edge
{
public:
	Edge(Condition* c, Node* n);
	~Edge();

	Condition* condition;
	Node* node;
};

