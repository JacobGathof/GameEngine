#include "MoveAction.h"
#include "LivingObject.h"

MoveAction::MoveAction(std::string& name, Vector2f& pos, float speed)
{
	object = (LivingObject *)World::getInstance()->getObject(name);
	goal = pos;
	ai = new GoToPointAI();
	ai->dest = goal;
	ai->speed = speed;
}

MoveAction::~MoveAction()
{
}

int MoveAction::run(float dt)
{
	if (ai->execute(object, dt)) {
		object->stalled = false;
		delete ai;
		return true;
	}
	
	object->stalled = true;
	return false;
}

NonBlockingMove::NonBlockingMove(std::string & name, Vector2f & pos, float speed) : MoveAction(name, pos, speed)
{
	
}

NonBlockingMove::~NonBlockingMove()
{
}

int NonBlockingMove::run(float dt)
{
	
	object->setAI(ai);
	return true;
}
