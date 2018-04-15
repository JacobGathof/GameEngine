#pragma once

#include "World.h"
#include "AbstractScriptAction.h"

class RoomChangeAction : public AbstractScriptAction
{
public:
	RoomChangeAction(std::string n);
	~RoomChangeAction();

	virtual int run(float dt);

private:

	std::string room;
};

