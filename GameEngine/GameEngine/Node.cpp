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

	int result = ACTION_COMPLETE;
	while (result == ACTION_COMPLETE && !completedAllActions) {
		result = actions[actionPtr]->run(dt);
		if (result == ACTION_COMPLETE) {
			actionPtr++;
			if (actionPtr >= actions.size()) {
				completedAllActions = true;
			}
		}
		if (result == ACTION_PAUSE) {
			status = NODE_HALTED;

			checkActionPtr = actions[actionPtr];

			actionPtr++;
			if (actionPtr >= actions.size()) {
				completedAllActions = true;
			}

			return n;
		}
	}

	if (completedAllActions) {
		n = getNextNode();
		if (n != 0) {
			n->resetNode();
		}
	}
	else {
		status = NODE_RUNNING;
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
		//std::cout << "Node dead end failure" << std::endl;
	}
	return n;
}

void Node::resetNode()
{
	status = NODE_RUNNING;
	actionPtr = 0;
	completedAllActions = false;
	for (auto a : actions) {
		a->reset();
	}
}

int Node::checkAction(float dt)
{
	if (checkActionPtr == 0) {
		return ACTION_COMPLETE;
	}
	return checkActionPtr->run(dt);
}

void Node::addAction(AbstractAction * act)
{
	actions.add(act);
}

void Node::setActions(List<AbstractAction*> act)
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
