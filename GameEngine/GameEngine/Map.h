#pragma once
#include "AbstractUIComponent.h"

class Map : public AbstractUIComponent
{
public:
	Map();
	~Map();

	virtual void draw();
	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);
	virtual void update(float dt);
};

