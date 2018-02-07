#pragma once
#include "AbstractUIComponent.h"

class Statusbar : public AbstractUIComponent
{
public:
	Statusbar();
	~Statusbar();
	virtual void draw();
	virtual void update(float dt);
	virtual void hover(Vector2f& pos);

private:
	Vector2f position;

	Vector2f topLeft = Vector2f(600, 790);
	Vector2f botRight = Vector2f(790, 100);
	Color hoverColor;

};

