#include "World.h"
#include "Room.h"
#include "Object.h"

World* World::inst;
std::map<std::string, Room *> World::rooms;

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
	//delete inst;
	for (auto r : rooms) {
		delete r.second;
	}
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
	Object* p = getObject(std::string("Player"));
	Object* closest = currentRoom->getNearestObject(p->pos);
	if (closest->pos.distanceTo(p->pos) < (-1) && closest != p) {

		closest->selected = true;
		closest->draw();
		closest->selected = false;

	}
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

	currentRoom->update(delta_time);
	currentRoom->checkCollisions();
}

void World::transition(Room * newRoom)
{
	/*
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
	*/
}

void World::setCurrentRoom(Room * r)
{
	currentRoom = r;
}

void World::setCurrentRoom(std::string & name)
{
	Room * room = rooms.at(name);
	if (room == nullptr) {
		std::cout << "Could not find room " << name << std::endl;
		return;
	}
	currentRoom = room;
}

InteractableObject * World::getNearestObject(Vector2f pos)
{
	return currentRoom->getNearestObject(pos);
}

Room * World::getRoom(std::string & name)
{
	return rooms.at(name);
}

void World::addRoom(std::string & name, Room * room)
{
	rooms[name] = room;
}

Object * World::getObject(std::string& name)
{
	return currentRoom->getObject(name);
}

Room * World::getCurrentRoom()
{
	return currentRoom;
}

void World::addObject(Object * obj)
{
	if (currentRoom != nullptr) {
		currentRoom->addObject(obj);
	}
	objects[obj->name] = obj;
}
