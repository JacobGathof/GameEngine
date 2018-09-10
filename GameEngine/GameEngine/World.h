#pragma once
#include "Vector2f.h"
#include <string>

#include "Room.h"
#include "List.h"

#include "GameState.h"
#include "BattleManager.h"


class Object;

class World
{
public:

	class RoomNames {
	public:
		static constexpr const char* READING_ROOM = "Reading Room";
		static constexpr const char* CLEARING = "Clearing";
		static constexpr const char* EAST = "East of Town";
	};


	~World();

	static World * getInstance();
	static void clean();

	void draw();
	void drawTerrain();
	void drawObjects();
	void drawObjectsInverted();
	void drawObjectsNegative();
	void eraseProjection(Vector2f& center, float radius, Object* pass);

	void drawEffects();
	void drawHitboxes();
	void drawLights();

	void update(float delta_time);
	void transition(Room * newRoom);

	Object * getNearestObject(Vector2f pos);

	Object * getObject(std::string& name);

	void setCurrentRoom(Room * r);
	void setCurrentRoom(const char* name);
	Room * getRoom(const char* name);
	void addRoom(const char* name, Room * room);

	Room * getCurrentRoom();
	void addObject(Object * obj);
	void removeObject(Object * obj);

	void addWorldObject(Object* obj);
	Object* getWorldObject(const char* name);

private:
	World();
	static std::map<std::string, Room *> rooms;
	static std::map<std::string, Object *> worldObjects;


	static World *inst;
	Room * currentRoom;
};

