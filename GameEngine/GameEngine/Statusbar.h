#pragma once
#include "AbstractUIComponent.h"

class Statusbar : public AbstractUIComponent
{
public:
	Statusbar();
	~Statusbar();
	virtual void draw();
	virtual void update(float dt);
	virtual void handleMouseEvents(Mouse& mouse);

private:

	Vector2f topLeft = Vector2f(600, 790);
	Vector2f botRight = Vector2f(790, 100);
	Color hoverColor;

};

