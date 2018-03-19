#pragma once

#include "Room.h"
class World
{
public:

	Room * currentRoom;

	static World * getInstance();
	static void clean();

	void draw();

	void drawTerrain();
	void drawObjects();
	void drawEffects();

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

