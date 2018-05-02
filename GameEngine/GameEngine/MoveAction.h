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
	MoveAction(std::string& name, Vector2f& pos, float speed = -1);
	~MoveAction();

	virtual int run(float dt);
protected:
	Vector2f goal;
	LivingObject * object;
	GoToPointAI * ai;
};

class NonBlockingMove : public MoveAction
{
public:
	NonBlockingMove(std::string& name, Vector2f& pos, float speed = -1);
	~NonBlockingMove();

	virtual int run(float dt);

};

