#include "Button.h"




Button::Button(Vector2f & pos, Vector2f & sc, std::string& txt, ButtonAction * act)
{
	position = pos;
	scale = sc;
	text = new Text(position, txt, Vector2f(50,50), Res::get(FontType::DEFAULT));
	action = act;

}

Button::~Button()
{
	delete text;
	delete action;
}

void Button::draw()
{
	switch (state) {
	case NONE: currentColor = defaultColor; break;
	case HOVER: currentColor = hoverColor; break;
	case CLICK: currentColor = clickColor; break;
	}

	UIUtils::drawRectangleIcon(position, scale, currentColor, 1.0f);
}

void Button::update(float dt)
{

}

void Button::hover(Vector2f & pos)
{
	if (pos.between(position, position + scale)) {
		state = ButtonState::HOVER;
	}
	else {
		state = ButtonState::NONE;
	}
}

void Button::click(Vector2f & pos)
{
	if (pos.between(position, position + scale)) {
		state = ButtonState::CLICK;
	}
}

void Button::release(Vector2f & pos)
{
	if (pos.between(position, position + scale)) {
		action->performAction();
	}
}

