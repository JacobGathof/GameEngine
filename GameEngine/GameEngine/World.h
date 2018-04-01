#pragma once
#include "Vector2f.h"
#include <string>

class Room;
class Object;

class World
{
public:


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
	Object * getNearestObject(Vector2f& pos);
	Object * getObject(std::string& name);

private:
	World();
	~World();

	static World *inst;
	Room * currentRoom;
};

