#include "Room.h"



Room::Room()
{
}


Room::~Room()
{
	for (Object * o : objects) {
		//delete o;
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
	
	for (int i = 0; i < objects.size(); i++) {
		
		
		Object * current = objects.at(i);
		for (int k = i+1; (k < objects.size() && (current->pos[1] < objects.at(k)->pos[1] + objects.at(k)->scale[1])); k++) {
			Object * obj = objects.at(k);
			if (collision(current, obj)) {
				current->collide(obj);
				obj->collide(current);
				std::cout << "" << std::endl;
			}
			
		}
		
	}
	
	
}

void Room::addObject(Object * obj)
{
	objects.push_back(obj);
}

void Room::sort()
{
	
	for (int i = 1; i < objects.size(); i++) {
		if (objects.at(i)->pos[1] > objects.at(i - 1)->pos[1]) {
			place(objects.at(i), i);
		}
	}
}

Object * Room::getNearestObject(Vector2f pos)
{
	Object * nearest;
	float nearestDist = 1000000;
	for (Object * obj : objects) {
		float dist = sqrt(pow(obj->pos[0] - pos[0], 2) + pow(obj->pos[1] - pos[1], 2));
		if (dist < nearestDist) {
			nearestDist = dist;
			nearest = obj;
		}
	}
	return nearest;
}

bool Room::collision(Object * obj1, Object * obj2)
{
	float x1 = obj1->pos[0];
	float y1 = obj1->pos[1];
	float xScale1 = obj1->scale[0];
	float yScale1 = obj1->scale[1];

	float x2 = obj2->pos[0];
	float y2 = obj2->pos[1];
	float xScale2 = obj2->scale[0];
	float yScale2 = obj2->scale[1];
	if (x1 < x2 + xScale2 && x2 < x1 + xScale1) {
		if (y1 < y2 + yScale2/2 && y2 < y1 + yScale1/2) {
			return true;
		}
	}
	
	return false;
}

void Room::place(Object * obj, int index)
{
	objects.erase(objects.begin() + index);
	for (int i = 0; i < objects.size(); i++) {
		if (obj->pos[1] > objects.at(i)->pos[1]) {
			objects.insert(objects.begin() + i, obj);
			return;
		}
	}
}
