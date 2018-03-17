#include "MoveAction.h"

MoveAction::MoveAction(std::string& name, Vector2f& pos)
{
	object = (LivingObject *)World::getInstance()->getObject(name);
	goal = pos;
	ai.dest = goal;
}

MoveAction::~MoveAction()
{
}

int MoveAction::run(float dt)
{
	
	if (ai.execute(object, dt)) {
		object->stalled = false;
		return true;
	}

	object->stalled = true;
	return false;
}
