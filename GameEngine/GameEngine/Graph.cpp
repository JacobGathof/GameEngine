#include "Graph.h"
#include "GraphLoader.h"


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
	while (n != 0) {
		current = n;
		n = current->update(dt);
	}
}

void Graph::setCurrentNode(std::string & s)
{
	auto k = nodeNames.find(s);
	if (k != nodeNames.end()) {
		current = nodes[nodeNames[s]];
	}
}

void Graph::createGraph()
{
	//GraphLoader::load(nodes, nodeNames, "res/script/cycle_1.txt");
	GraphLoader::load(nodes, nodeNames,"res/script/test.txt");
	
	/*
	nodes.push_back(new Node());
	nodes.push_back(new Node());

	nodes[0]->addAction(new TextAction(std::string("Testing the scripting system"), true));
	nodes[0]->addAction(new MoveAction("Melody", Vector2f(100, 200)));
	nodes[0]->addAction(new TextAction(std::string("Let this string overflow the boundary - demonstrate text wrapping")));
	nodes[0]->addAction(new TextChoiceAction({ std::string("Choice1") , std::string("Repeat") , std::string("Choice3"), std::string("Choice4") }));
	nodes[0]->addAction(new BannerAction(std::string("The Echo Effect"), std::string("50% more Gilgamesh")));
	nodes[0]->addAction(new WaitAction(0.5f));
	nodes[0]->addAction(new TextAction(std::string("Screen fade in/out")));
	nodes[0]->addAction(new ScreenFadeAction(Color::White, 1.0f, SCREEN_FADE_OUT));
	nodes[0]->addAction(new ScreenFadeAction(Color::White, 1.0f, SCREEN_FADE_IN));
	nodes[0]->addAction(new SetAction<float>(&GameState::ui_blue, 0.0f));
	nodes[0]->addAction(new TextAction(std::string("End of node actions")));
	nodes[0]->addAction(new DebugAction("Node 0 done"));

	nodes[0]->addEdge(new Edge(new ChoiceCondition(1, true), nodes[0]));
	nodes[0]->addEdge(new Edge(new ChoiceCondition(1, false), nodes[1]));




	nodes[1]->addAction(new TextAction(std::string("2nd Node")));
	nodes[1]->addAction(new TextAction(std::string("This node will repeat")));
	nodes[1]->addAction(new TextChoiceAction({ std::string("Choice 1") , std::string("Choice 2") }));
	nodes[1]->addAction(new WaitAction(0.5f));
	nodes[1]->addAction(new DebugAction("Node 2 done"));

	nodes[1]->addEdge(new Edge(new IntCondition(1, 1), nodes[1]));
	*/

}
