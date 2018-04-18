#pragma once

#include "AbstractAction.h"
#include "Vector2f.h"
#include "World.h"
#include "GoToPointAI.h"
#include <string>

class LivingObject;

class MoveAction : public AbstractAction
{
public:
	MoveAction(std::string& name, Vector2f& pos);
	~MoveAction();

	virtual int run(float dt);
private:
	Vector2f goal;
	LivingObject * object;
	GoToPointAI ai;
};

