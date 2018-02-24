#pragma once
#include "Node.h"
#include <vector>

class Graph
{
public:
	Graph();
	~Graph();
	void update(float dt);

	Node* root;
	Node* current;
	std::vector<Node*> nodes;
};

