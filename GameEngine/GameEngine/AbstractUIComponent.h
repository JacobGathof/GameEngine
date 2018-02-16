#pragma once
#include "UIUtils.h"

class AbstractUIComponent
{
public:
	AbstractUIComponent();
	~AbstractUIComponent();

	virtual void hover(Vector2f& pos);
	virtual void click(Vector2f& pos);
	virtual void release(Vector2f& pos);
	virtual void move(Vector2f& pos);
	virtual void update(float dt);
	virtual void draw();
	void setParentPosition(Vector2f* pos);

protected:
	Vector2f * parentOffset;
	Vector2f position;
	Vector2f scale;

	Vector2f baseOffset;
};

