#pragma once
#include <vector>
#include <math.h>
#include "TerrainMap.h"
#include "List.h"
#include "Rectangle.h"
#include "RectHitbox.h"

class Object;

class Room
{
public:
	Room();
	~Room();
	//std::vector<Object *> transitions; maybe

	std::string name;

	void update(float delta_time);
	void draw();

	void drawTerrain();
	void drawObjects();
	void drawEffects();
	void drawHitboxes();

	void checkCollisions();
	void addObject(Object * obj);
	void sort();
	Object * getNearestObject(Vector2f pos);
	Object * getObject(std::string name);
	void setTerrainMap(std::string map);
	void addHitbox(Vector2f pos, Vector2f scale);

private:
	List<Object *> objects;
	TerrainMap terrain;
	std::map<std::string, Object *> objectMap;
	Object * collisionObject;

	Hitbox * oneCarry;
	Hitbox * twoCarry;

	bool collision(Object * obj1, Object * obj2);
	void sortPlace(Object * obj, int index);

};

