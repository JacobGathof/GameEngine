#include "Room.h"
#include "Object.h"

Room::Room()
{
	collisionObject = new Object("extra", TextureType::TEXTURE_DEFAULT, Vector2f(0,0), Vector2f(1,1));
}


Room::~Room()
{
	for (Object * o : objects) {
		//delete o;
	}
	delete collisionObject;
	
	
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
	collisionObject->draw();
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
				
			}
		}
		if (collision(current, collisionObject)) {
			current->collide(collisionObject, twoCarry);
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

void Room::addHitbox(Vector2f pos, Vector2f scale)
{
	Hitbox * hit = new RectHitbox(Rect(pos,scale), pos);
	collisionObject->addHitbox(hit);
}

bool Room::collision(Object * obj1, Object * obj2)
{
	for (int i = 0; i < obj1->numHitboxes(); i++) {
		Hitbox * one = obj1->getHitbox(i);
		for (int k = 0; k < obj2->numHitboxes(); k++) {
			Hitbox * two = obj2->getHitbox(k);
			if (one->pos == two->pos) {
				continue;
			}
			if (one->collide(two)) {
				obj1->collide(obj2, two);
				obj2->collide(obj1, one);
			}
		}
	}
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
