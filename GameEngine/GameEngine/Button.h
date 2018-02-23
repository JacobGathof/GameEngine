#pragma once
#include "AbstractUIComponent.h"
#include "ButtonAction.h"
#include "Text.h"

enum ButtonState {
	NONE,
	HOVER,
	CLICK,
};

class Button : public AbstractUIComponent
{

public:
	Button(Vector2f& pos, Vector2f& sc, std::string& txt, ButtonAction* act);
	~Button();
	virtual void draw();
	virtual void update(float dt);
	virtual void handleMouseEvents(Mouse& mouse);

private:
	Text* text = 0;
	ButtonAction* action = 0;
	Color defaultColor[3] = { Color(0xffffffff), Color(0x0000ffff), Color(0xddddddff) };
	Color hoverColor[3] = { Color(0x8888ffff), Color(0x0000ffff), Color(0xffffffff) };
	Color clickColor[3] = { Color(0x888888ff), Color(0x0000ffff), Color(0x888888ff) };
	Color * currentColor = defaultColor;
	ButtonState state = ButtonState::NONE;
};
