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
	int readyToRun(float dt);
	bool graphComplete();

	void setCurrentNode(std::string& s);
	void reset();

private:
	void createGraph();

	Node* current;
	std::vector<Node*> nodes;
	std::map < std::string, int> nodeNames;
	int graphStatus = NODE_RUNNING;

};

