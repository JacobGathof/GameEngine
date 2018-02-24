#include "Node.h"
#include "TextAction.h"
#include "TextChoiceAction.h"
#include "DebugAction.h"

Node::Node()
{
	actions.add(new TextAction(std::string("Hello World")));
	actions.add(new TextAction(std::string("Hello World1")));
	actions.add(new TextAction(std::string("Hello World2")));
	actions.add(new TextAction(std::string("Hello World3")));
	actions.add(new TextAction(std::string("Hello World4")));
	std::string choices[2] = { std::string("Hello World4") , std::string("Hello World4") };
	actions.add(new TextChoiceAction(choices, 2));

	actions.add(new DebugAction("Messages done"));
	actions.add(new TextAction(std::string("Hello World End")));

	conditions.add(new Edge(new Condition(1, 1), this));
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

	if (completedAllActions) {
		n = getNextNode();
		if (n != 0) {
			n->resetNode();
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
}
