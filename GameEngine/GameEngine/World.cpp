#include "World.h"


World* World::inst;


World::World()
{
}


World::~World()
{
	delete inst;
}

World * World::getInstance()
{
	if (inst == nullptr) {
		inst = new World();
	}

	return inst;
}

void World::draw()
{
	currentRoom.draw();
}

void World::update(float delta_time)
{
	//Maybe want to switch these.
	currentRoom.checkCollisions();
	currentRoom.update(delta_time);
}

void World::transition(Room newRoom)
{
	//Need to transfer over some objects(Player and Party)
	currentRoom = newRoom;
}
