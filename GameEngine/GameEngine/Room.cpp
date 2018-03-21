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
	for (auto o : objects) {
		o->update(delta_time);
	}
}

void Room::draw()
{
	drawTerrain();
	drawObjects();
	drawEffects();
}

void Room::drawTerrain()
{
	terrain.draw(objectMap.at("Melody"));
}

void Room::drawObjects()
{
	for (Object * o : objects) {
		o->draw();
	}
}

void Room::drawEffects()
{
	for (Object * o : objects) {
		o->drawEffects();
	}
}

void Room::checkCollisions()
{
	
	for (int i = 0; i < objects.size(); i++) {
		Object * current = objects.get(i);
		for (int k = i; k < objects.size(); k++) {
			Object * other = objects.get(k);
			if (collision(current, other)) {
				current->collide(other);
				other->collide(current);
			}
		}

		/*
		for (int k = i+1; (k < objects.size() && (current->pos[1] < objects[k]->pos[1] + objects[k]->scale[1])); k++) {
			Object * obj = objects.get(k);
			if (collision(current, obj)) {
				current->collide(obj);
				obj->collide(current);
			}
			
		}
		*/
	}
	
	
}

void Room::addObject(Object * obj)
{
	std::cout << obj->name << std::endl;
	objects.add(obj);
	objectMap.insert(std::pair<std::string, Object *>(obj->name, obj));
}

void Room::sort()
{
	for (int i = 1; i < objects.size(); i++) {
		if (objects[i]->pos[1] > objects[i - 1]->pos[1]) {
			sortPlace(objects[i], i);
		}
	}
}

Object * Room::getNearestObject(Vector2f pos)
{
	Object * nearest = nullptr;
	float nearestDist = 1000000;
	for (Object * obj : objects) {
		float dist = pos.distanceTo(obj->pos);
		if (dist < nearestDist && dist != 0) {
			nearestDist = dist;
			nearest = obj;
		}
	}
	return nearest;
}

Object * Room::getObject(std::string name)
{
	std::cout << objectMap.size() << std::endl;
	return objectMap.at(name);
}

void Room::setTerrainMap(std::string map)
{
	terrain.constructMap("TerrainMaps/" + map);
}

bool Room::collision(Object * obj1, Object * obj2)
{
	
	for (int i = 0; i < obj1->numHitboxes(); i++) {
		Hitbox * one = obj1->getHitbox(i);
		for (int k = 0; k < obj2->numHitboxes(); k++) {
			Hitbox * two = obj2->getHitbox(i);
			if (one->pos == two->pos) {
				continue;
			}
			if (one->collide(two)) {
				return true;
			}
		}
	}


	//Will be the square-square hitbox later
	/*
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
	*/
	return false;
}

void Room::sortPlace(Object * obj, int index)
{
	objects.removeIndex(index);
	for (int i = 0; i < objects.size(); i++) {
		if (obj->pos[1] > objects[i]->pos[1]) {
			objects.add(obj, i);
			return;
		}
	}
}
