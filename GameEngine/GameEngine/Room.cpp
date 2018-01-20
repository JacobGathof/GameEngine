#include "Room.h"



Room::Room()
{
}


Room::~Room()
{
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
