#pragma once
#include "Screen.h"
#include "AbstractScriptAction.h"


class MoveCameraAction : public AbstractScriptAction
{
public:
	MoveCameraAction(float xPos, float yPos);
	~MoveCameraAction();

	virtual int run(float dt);
	virtual void reset();

	Vector2f pos;
};

