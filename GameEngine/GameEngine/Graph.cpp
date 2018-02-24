#include "Graph.h"
#include "TextAction.h"
#include "TextChoiceAction.h"
#include "DebugAction.h"
#include "WaitAction.h"
#include "ScreenFadeAction.h"
#include "SetAction.h"


Graph::Graph()
{
	createGraph();
	current = nodes[0];
}


Graph::~Graph()
{
	for (auto n : nodes) {
		delete n;
	}
}

void Graph::update(float dt)
{
	Node* n = current->update(dt);
	if (n != 0) {
		current = n;
	}
}

void Graph::createGraph()
{
	nodes.push_back(new Node());
	nodes.push_back(new Node());

	nodes[0]->addAction(new TextAction(std::string("Hello World")));
	nodes[0]->addAction(new TextAction(std::string("Hello World1")));
	std::string choices[2] = { std::string("Hello World4") , std::string("Hello World4") };
	nodes[0]->addAction(new TextChoiceAction(choices, 2));
	nodes[0]->addAction(new WaitAction(1.0f));
	nodes[0]->addAction(new ScreenFadeAction(Color(0xffffffff), 2.0f, 0));
	nodes[0]->addAction(new ScreenFadeAction(Color(0xffffffff), 2.0f, 1));
	nodes[0]->addAction(new SetAction<float>(&GameState::ui_blue, 0.0f));
	nodes[0]->addAction(new DebugAction("Node 0 done"));

	nodes[0]->addEdge(new Edge(new Condition(2, 1), nodes[0]));
	nodes[0]->addEdge(new Edge(new Condition(1, 1), nodes[1]));




	nodes[1]->addAction(new TextAction(std::string("Hell0")));
	nodes[1]->addAction(new TextAction(std::string("Hello")));
	nodes[1]->addAction(new TextChoiceAction(choices, 2));
	nodes[1]->addAction(new WaitAction(2.0f));
	nodes[1]->addAction(new DebugAction("Node 1 done"));

	nodes[1]->addEdge(new Edge(new Condition(1, 1), nodes[1]));

}
