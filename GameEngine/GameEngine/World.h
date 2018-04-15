#pragma once

#include "Room.h"
#include "List.h"
class World
{
public:

	~World();

	Room * currentRoom;

	static World * getInstance();
	void draw();
	void update(float delta_time);
	void transition(Room * newRoom);
	void setCurrentRoom(Room * r);
	void setCurrentRoom(std::string& name);
	Object * getNearestObject(Vector2f pos);
	Object * getObject(std::string& name);
	Room * getRoom(std::string& name);
	void addRoom(std::string& name, Room * room);

private:
	World();
	std::map<std::string, Room *> rooms;

	static World *inst;
};

