#pragma once
#include "Node.h"
#include <vector>
#include <map>
#include <algorithm>

class Graph
{
public:
	Graph();
	Graph(char* filename);
	~Graph();
	int update(float dt);

	void setCurrentNode(std::string& s);

private:
	void createGraph();

	Node* current;
	std::vector<Node*> nodes;
	std::map < std::string, int> nodeNames;

};

