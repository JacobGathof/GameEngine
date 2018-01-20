#include "World.h"



World::World()
{
}


World::~World()
{
}

void World::draw()
{
	//Maybe want to switch these.
	currentRoom.draw();
	currentRoom.checkCollisions();
}

void World::update(float delta_time)
{
	currentRoom.update(delta_time);
}

void World::transition(Room newRoom)
{
	//Need to transfer over some objects(Player and Party)
	currentRoom = newRoom;
}
