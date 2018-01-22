#include "Room.h"



Room::Room()
{
}


Room::~Room()
{
	for (Object * o : objects) {
		delete o;
	}
}

void Room::update(float delta_time)
{
	for (Object * o : objects) {
		o->update(delta_time);
	}
}

void Room::draw()
{
	for (Object * o : objects) {
		o->draw();
	}
}

void Room::checkCollisions()
{
	//TODO: implement this later;
}

void Room::addObject(Object * obj)
{
	objects.push_back(obj);
}
