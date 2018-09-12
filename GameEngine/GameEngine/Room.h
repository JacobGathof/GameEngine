#pragma once
#include <vector>
#include <math.h>
#include "TerrainMap.h"
#include "List.h"
#include "Rectangle.h"
#include "RectHitbox.h"
#include "CircleHitbox.h"
#include "Circle.h"
#include "FilesAndStrings.h"


class Room
{
public:
	Room();
	~Room();
	//std::vector<Object *> transitions; maybe

	std::string name;

	void update(float dt);
	void draw();

	void drawTerrain();
	void drawObjects();
	void drawObjectsInverted();
	void drawObjectsNegative();
	void eraseProjection(Vector2f& center, float radius, Object* pass);

	void drawEffects();
	void drawHitboxes();
	void drawLights();

	void checkCollisions();
	void addObject(Object * obj);

	void addWorldObject(Object* obj);

	void sortObjects();

	Object * getNearestObject(Vector2f& pos);
	Object * getObject(std::string& name);
	void setTerrainMap(List<TextureType>& layers);
	void loadObjects(std::string& filepath);

	void eraseObject(Object* obj);
	void removeObject(Object * obj);

	List<Object *>& getObjects();

protected:

	List<Object *> objects;

	List<Object*> allRoomObjects;


	TerrainMap* terrain;
	std::map<std::string, Object *> objectMap;

	std::map<std::string, TextureType> textureMap;

	Hitbox * oneCarry;
	Hitbox * twoCarry;

	void init();
	bool collision(Object * obj1, Object * obj2);

};

