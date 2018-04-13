#include "World.h"


World* World::inst;


World::World()
{
}


World::~World()
{
	delete inst;

	for (Room * room : rooms) {
		delete room;
	}
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
	currentRoom->draw();
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

Object * World::getNearestObject(Vector2f pos)
{

	return currentRoom->getNearestObject(pos);
}

Object * World::getObject(std::string name)
{
	return currentRoom->getObject(name);
}
