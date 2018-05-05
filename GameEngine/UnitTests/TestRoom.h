#pragma once

#include "../GameEngine/Room.h"

class TestRoom : public Room
{
public:
	TestRoom();
	~TestRoom();

	bool collideTest(Object * obj, Object * obj2);

};

