#pragma once

#include <vector>
#include <math.h>
#include "Object.h"
class Room
{
public:
	Room();
	~Room();

	std::vector<Object *> objects;
	//TerrainMap terrain;
	//std::vector<Object *> transitions; maybe

	void update(float delta_time);
	void draw();
	void checkCollisions();
	void addObject(Object * obj);
	void sort();
	Object * getNearestObject(Vector2f pos);

private:
	bool collision(Object * obj1, Object * obj2);
	void place(Object * obj, int index);
};

