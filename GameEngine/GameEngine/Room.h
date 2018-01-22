#pragma once

#include <vector>
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
};

