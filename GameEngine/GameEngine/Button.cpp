#include "Button.h"
#include "Text.h"


Button::Button(Vector2f & pos, Vector2f & sc, std::string& txt, ButtonAction * act)
{
	position = pos;
	scale = sc;
	text = new Text(position+scale/2, txt, Vector2f(sc[1]/2.0f, sc[1]/2.0f), 0);
	text->center();
	text->setColor(Color::Black);
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
	text->draw();
}

void Button::update(float dt)
{

}

void Button::handleMouseEvents(Mouse & mouse)
{
	state = ButtonState::NONE;
	if (mouse.pos().between(position, position + scale)) {
		state = ButtonState::HOVER;
		if(mouse.down()){
			state = ButtonState::CLICK;
		}
		else if (mouse.release()) {
			action->performAction();
		}
	}

}

void Button::handleKeyEvents(Keyboard & keyboard)
{
}

