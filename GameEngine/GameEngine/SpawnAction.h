#pragma once

#include "AbstractAction.h"
#include "World.h"
#include <string>

class SpawnAction : public AbstractAction
{
public:
	SpawnAction(std::string& name, Vector2f pos);
	~SpawnAction();

	virtual int run(float dt);

private:
	std::string name;
	std::string type;
	Vector2f position;
};

