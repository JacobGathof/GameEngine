#include "World.h"
#include "Object.h"

World* World::inst;
std::map<std::string, Room *> World::rooms;
std::map<std::string, Object *> World::worldObjects;


World::~World(){}

World::World() {

}



World * World::getInstance()
{
	if (inst == 0) {
		inst = new World();
	}

	return inst;
}

void World::clean()
{
	for (auto r : rooms) {
		delete r.second;
	}
	if (inst != 0) {
		delete inst;
	}
	for (auto a : worldObjects) {
		delete a.second;
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

void World::drawObjectsInverted()
{
	currentRoom->drawObjectsInverted();
}

void World::drawObjectsNegative()
{
	currentRoom->drawObjectsNegative();
}

void World::eraseProjection(Vector2f & center, float radius, Object* pass)
{
	currentRoom->eraseProjection(center, radius, pass);
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
	
	List<Object *> objs = currentRoom->getObjects();

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
	currentRoom = r;

}

void World::setCurrentRoom(const char* name)
{
	Room * room = rooms.at(name);
	if (room == nullptr) {
		std::cout << "Could not find room " << name << std::endl;
		return;
	}
	setCurrentRoom(room);
}

Object * World::getNearestObject(Vector2f pos)
{
	return currentRoom->getNearestObject(pos);
}

Room * World::getRoom(const char * name)
{
	return rooms[name];
}

void World::addRoom(const char * name, Room * room)
{
	rooms[name] = room;
}

Object * World::getObject(std::string& name)
{
	Object* o = currentRoom->getObject(name);
	if (o == 0) {
		o = worldObjects[name];
	}
	return o;
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
}

void World::removeObject(Object * obj)
{
	currentRoom->removeObject(obj);
}


void World::addWorldObject(Object * obj){
	worldObjects[obj->name] = obj;
}

Object * World::getWorldObject(const char * name)
{
	return worldObjects[name];
}
