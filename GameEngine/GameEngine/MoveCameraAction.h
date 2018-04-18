#pragma once
#include "Screen.h"
#include "AbstractAction.h"


class MoveCameraAction : public AbstractAction
{
public:
	MoveCameraAction(float xPos, float yPos);
	~MoveCameraAction();

	virtual int run(float dt = 0.0f);
	virtual void reset();

	Vector2f pos;
};

