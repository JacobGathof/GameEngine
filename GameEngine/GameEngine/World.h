#pragma once

#include "Room.h"
class World
{
public:
	World();
	~World();

	Room currentRoom;

	void draw();
	void update(float delta_time);
	void transition(Room newRoom);
};

