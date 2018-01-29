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

	void update(float delta_time);
	void draw();
	void checkCollisions();
	void addObject(Object * obj);
	void sort();
	Object * getNearestObject(Vector2f pos);

private:
	List<Object *> objects;
	TerrainMap terrain;

	bool collision(Object * obj1, Object * obj2);
	void sortPlace(Object * obj, int index);

};

