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
};

