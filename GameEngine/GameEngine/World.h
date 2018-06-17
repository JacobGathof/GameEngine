#pragma once
#include "Vector2f.h"
#include <string>

#include "Room.h"
#include "List.h"
class Room;
class Object;

#include "GameState.h"
#include "BattleManager.h"
class World
{
public:

	~World();

	static World * getInstance();
	static void clean();

	void draw();

	void drawTerrain();
	void drawObjects();
	void drawEffects();
	void drawHitboxes();
	void drawLights();

	void update(float delta_time);
	void transition(Room * newRoom);
	void setCurrentRoom(Room * r);
	void setCurrentRoom(std::string& name);
	InteractableObject * getNearestObject(Vector2f pos);
	Object * getObject(std::string& name);
	Room * getRoom(std::string& name);
	void addRoom(std::string& name, Room * room);
	Room * getCurrentRoom();
	void addObject(Object * obj);

private:
	World();
	static std::map<std::string, Room *> rooms;
	std::map<std::string, Object *> objects;

	static World *inst;
	Room * currentRoom;
};

