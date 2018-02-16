#pragma once
#include "AbstractUIComponent.h"

class CardsPage : public AbstractUIComponent
{
public:
	CardsPage();
	~CardsPage();
	virtual void draw();
	virtual void update(float dt);
	virtual void hover(Vector2f& pos);
	virtual void click(Vector2f& pos);
};

