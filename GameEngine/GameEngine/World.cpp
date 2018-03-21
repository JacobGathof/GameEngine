#include "World.h"


World* World::inst;


World::World(){}
World::~World(){}


World * World::getInstance()
{
	if (inst == nullptr) {
		inst = new World();
	}

	return inst;
}

void World::clean()
{
	if (inst != 0) {
		delete inst;
	}
}

void World::draw()
{
	drawTerrain();
	drawObjects();
	drawEffects();
}

void World::drawTerrain()
{
	currentRoom->drawTerrain();
}

void World::drawObjects()
{
	currentRoom->drawObjects();
}

void World::drawEffects()
{
	currentRoom->drawEffects();
}

void World::update(float delta_time)
{
	//Maybe want to switch these.
	currentRoom->sort();
	
	currentRoom->update(delta_time);
	currentRoom->checkCollisions();
}

void World::transition(Room * newRoom)
{
	//Need to transfer over some objects(Player and Party)
	currentRoom = newRoom;
}

void World::setCurrentRoom(Room * r)
{
	currentRoom = r;
}

Object * World::getNearestObject(Vector2f pos)
{

	return currentRoom->getNearestObject(pos);
}

Object * World::getObject(std::string name)
{
	return currentRoom->getObject(name);
}
