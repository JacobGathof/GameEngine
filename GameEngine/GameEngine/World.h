#pragma once

#include "Room.h"
class World
{
public:

	Room * currentRoom;

	static World * getInstance();
	void draw();
	void update(float delta_time);
	void transition(Room * newRoom);
	void setCurrentRoom(Room * r);
	Object * getNearestObject(Vector2f pos);
	Object * getObject(std::string name);

private:
	World();
	~World();

	static World *inst;
};

