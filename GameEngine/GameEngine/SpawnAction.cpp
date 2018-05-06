#include "SpawnAction.h"



SpawnAction::SpawnAction(std::string & n,Vector2f pos)
{
	name = n;
	position = pos;
}

SpawnAction::~SpawnAction()
{
}

int SpawnAction::run(float dt)
{
	World * world = World::getInstance();
	Object * obj = world->getObject(name);
	obj->pos = position;
	world->addObject(obj);
	return true;
}
