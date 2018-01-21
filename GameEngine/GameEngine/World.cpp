#include "World.h"



World::World()
{
}


World::~World()
{
}

void World::draw()
{
	currentRoom.draw();
}

void World::update(float delta_time)
{
	//Maybe want to switch these.
	currentRoom.update(delta_time);
	currentRoom.checkCollisions();
}

void World::transition(Room newRoom)
{
	//Need to transfer over some objects(Player and Party)
	currentRoom = newRoom;
}
