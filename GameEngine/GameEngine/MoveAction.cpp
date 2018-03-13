#include "MoveAction.h"

MoveAction::MoveAction(std::string name, Vector2f pos)
{
	object = World::getInstance()->getObject(name);
	goal = pos;
	ai.dest = goal;
}

MoveAction::~MoveAction()
{
}

int MoveAction::run(float dt)
{
	
	if (ai.execute((LivingObject *)object, dt)) {
		object->stalled = true;
		return true;
	}

	object->stalled = false;
	return false;
}
