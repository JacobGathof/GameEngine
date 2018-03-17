#include "Node.h"


Node::Node()
{
	
}


Node::~Node()
{
	for (auto a : actions) {
		delete a;
	}

	for (auto e : conditions) {
		delete e;
	}

}

Node* Node::update(float dt)
{
	Node* n = 0;


	if (completedAllActions) {
		n = getNextNode();
		if (n != 0) {
			n->resetNode();
		}
	}


	int result = 1;
	while (result == 1 && !completedAllActions) {
		result = actions[actionPtr]->run(dt);
		if (result == 1) {
			actionPtr++;
			if (actionPtr >= actions.size()) {
				completedAllActions = true;
			}
		}
	}

	return n;
}

Node * Node::getNextNode()
{
	Node* n = 0;
	for (auto l : conditions) {
		if (l->condition->evaluate()) {
			n = l->node;
			break;
		}
	}

	if (n == 0) {
		std::cout << "Node dead end failure" << std::endl;
	}
	return n;
}

void Node::resetNode()
{
	actionPtr = 0;
	completedAllActions = false;
	for (auto a : actions) {
		a->reset();
	}
}

void Node::addAction(AbstractScriptAction * act)
{
	actions.add(act);
}

void Node::setActions(List<AbstractScriptAction*> act)
{
	actions.clear();
	actions.addAll(act);
}

void Node::addEdge(Edge * edge)
{
	conditions.add(edge);
}

void Node::setEdges(List<Edge*> edges)
{
	conditions.clear();
	conditions.addAll(edges);
}
