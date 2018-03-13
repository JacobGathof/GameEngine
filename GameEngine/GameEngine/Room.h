#pragma once
#include <vector>
#include <math.h>
#include "Object.h"
#include "TerrainMap.h"
#include "List.h"

class Room
{
public:
	Room();
	~Room();
	//std::vector<Object *> transitions; maybe

	std::string name;

	void update(float delta_time);
	void draw();
	void checkCollisions();
	void addObject(Object * obj);
	void sort();
	Object * getNearestObject(Vector2f pos);
	Object * getObject(std::string name);

private:
	List<Object *> objects;
	TerrainMap terrain;
	std::map<std::string, Object *> objectMap;

	bool collision(Object * obj1, Object * obj2);
	void sortPlace(Object * obj, int index);

};

