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

class CollidableObject;

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
	void drawEffects();
	void drawHitboxes();
	void drawLights();

	void checkCollisions();
	void addObject(Object * obj);
	void addObject(CollidableObject * obj);
	void addObject(InteractableObject* obj);

	void addWorldObject(InteractableObject* obj);

	void sortObjects();

	InteractableObject * getNearestObject(Vector2f& pos);
	Object * getObject(std::string& name);
	void setTerrainMap(std::string& map);
	void addHitbox(Vector2f& pos, Vector2f& scale);
	void loadObjects(std::string& filepath);

	void removeObject(Object * obj);
	void removeCollidableObject(CollidableObject* obj);
	void removeInteractableObject(InteractableObject* obj);

	List<InteractableObject *>& getInteractableObjects();
	List<CollidableObject *>& getCollidableObjects();

protected:

	List<InteractableObject *> interactableObjects;
	List<CollidableObject *> collidableObjects;
	List<Object *> simpleObjects;

	List<Object*> allRoomObjects;


	TerrainMap terrain;
	std::map<std::string, Object *> objectMap;

	CollidableObject * collisionObject;
	std::map<std::string, TextureType> textureMap;

	Hitbox * oneCarry;
	Hitbox * twoCarry;

	void init();
	bool collision(CollidableObject * obj1, CollidableObject * obj2);

};

