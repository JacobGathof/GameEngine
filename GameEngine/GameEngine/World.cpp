#include "World.h"
#include "Room.h"
#include "Object.h"

World* World::inst;

World::World(){}
World::~World(){
	/*
	std::cout << "Rooms: " << rooms.size() << std::endl;
	for (int i = 0; i < rooms.size(); i++) {
		if (room != nullptr) {
			delete room;
		}
	}
	*/
}


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
	drawHitboxes();
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

void World::drawHitboxes()
{
	currentRoom->drawHitboxes();
}

void World::drawLights()
{
	currentRoom->drawLights();
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
	List<Object *> objs = currentRoom->getObjects();
	objs.addAll(currentRoom->getStaticObjects());
	for (int i = 0; i < objs.size(); i++) {
		Object * obj = objs.get(i);
		if (obj->persistent) {
			currentRoom->removeObject(obj);
			newRoom->addObject(obj);
		}
	}

	currentRoom = newRoom;
}

void World::setCurrentRoom(Room * r)
{
	rooms.add(r);
	currentRoom = r;
}

Object * World::getNearestObject(Vector2f& pos)
{

	return currentRoom->getNearestObject(pos);
}

Object * World::getObject(std::string& name)
{
	return currentRoom->getObject(name);
}

Room * World::getCurrentRoom()
{
	return currentRoom;
}
