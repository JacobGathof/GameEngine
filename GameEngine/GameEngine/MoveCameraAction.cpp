#include "MoveCameraAction.h"



MoveCameraAction::MoveCameraAction(float xPos, float yPos)
{
	pos = Vector2f(xPos, yPos);
}

MoveCameraAction::~MoveCameraAction()
{
}

int MoveCameraAction::run(float dt)
{
	Screen::moveTo(pos);
	Screen::follow(pos);
	return 1;
}

void MoveCameraAction::reset()
{
	
}
