#include "RoomChangeAction.h"



RoomChangeAction::RoomChangeAction(std::string n)
{
	room = n;
}

RoomChangeAction::~RoomChangeAction()
{
}

int RoomChangeAction::run(float dt)
{
	World * world = World::getInstance();
	Room * r = world->getRoom(room.c_str());
	world->transition(r);
	return 1;
}
