#pragma once
#include "AbstractUIComponent.h"

class Text;
class AbstractAction;

class Slider : public AbstractUIComponent
{

public:
	Slider(Vector2f& pos, Vector2f& sc, std::string& t, float* ref, float mi, float ma, int ic, AbstractAction* act = 0);
	~Slider();
	virtual void draw();
	virtual void update(float dt);
	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);
private:
	Text * data;
	Text * title;

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

	AbstractAction* action;
};

