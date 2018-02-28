#pragma once
#include "UIUtils.h"
#include "Mouse.h"
#include "Keyboard.h"

class AbstractUIComponent
{
public:
	AbstractUIComponent();
	~AbstractUIComponent();

	virtual void handleMouseEvents(Mouse& mouse) = 0;
	virtual void handleKeyEvents(Keyboard& keyboard) = 0;
	virtual void update(float dt);
	virtual void draw() = 0;
	void setParentPosition(Vector2f* pos);
	bool mouseIn(Mouse& mouse);

protected:
	Vector2f * parentOffset;
	Vector2f position;
	Vector2f scale;
};

