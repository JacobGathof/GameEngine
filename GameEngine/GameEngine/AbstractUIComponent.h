#pragma once
#include "UIUtils.h"
#include "Mouse.h"
#include "Keyboard.h"

class AbstractUIComponent
{
public:
	AbstractUIComponent();
	~AbstractUIComponent();

	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);
	virtual void update(float dt);
	virtual void draw() = 0;
	void setParentPosition(Vector2f* pos);
	bool mouseIn(Mouse& mouse);
	virtual void resize(int newX, int newY);
	virtual void setVisible(bool b);

protected:
	Vector2f * parentOffset;
	Vector2f position;
	Vector2f scale;
	bool visible;
};

