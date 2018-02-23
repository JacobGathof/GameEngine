#pragma once
#include "AbstractUIComponent.h"

class Slider : public AbstractUIComponent
{

public:
	Slider(Vector2f& pos, Vector2f& sc, float* ref, float mi, float ma, int ic);
	~Slider();
	virtual void draw();
	virtual void update(float dt);
	virtual void hover(Vector2f& pos);
	virtual void click(Vector2f& pos);
	virtual void release(Vector2f& pos);
private:

	Color defaultColor[3] = { Color(0xffffffff), Color(0x0000ffff), Color(0xddddddff) };
	Color hoverColor[3] = { Color(0x8888ffff), Color(0x0000ffff), Color(0xffffffff) };
	Color clickColor[3] = { Color(0x888888ff), Color(0x0000ffff), Color(0x888888ff) };
	Color * currentColor = defaultColor;
	bool held = false;

	float* ref;

	float minX = 0;
	float maxX = 8;
	int inc = 8;

	float ptr = minX;
};

