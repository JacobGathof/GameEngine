#pragma once
#include "AbstractUIComponent.h"

class CardsPage : public AbstractUIComponent
{
public:
	CardsPage();
	~CardsPage();
	virtual void draw();
	virtual void update(float dt);
	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);
};

