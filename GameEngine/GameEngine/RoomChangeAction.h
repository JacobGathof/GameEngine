#pragma once

#include "World.h"
#include "AbstractAction.h"

class RoomChangeAction : public AbstractAction
{
public:
	RoomChangeAction(std::string n);
	~RoomChangeAction();

	virtual int run(float dt = 0.0f);

private:

	std::string room;
};

