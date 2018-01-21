#pragma once

#include "Room.h"
class World
{
public:

	Room currentRoom;

	static World * getInstance();
	void draw();
	void update(float delta_time);
	void transition(Room newRoom);

private:
	World();
	~World();

	static World *inst;
};

