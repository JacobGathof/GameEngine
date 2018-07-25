#include "InputTextArea.h"
#include "GameState.h"



InputTextArea::InputTextArea(Vector2f & pos, Vector2f & sc)
{
	position = pos;
	scale = sc;
	text = new Text(position + Vector2f(scale[1]/2, scale[1] / 4), std::string(""), Vector2f(sc[1] / 2.0f, sc[1] / 2.0f), 0);
	text->setColor(Color::White);
}

InputTextArea::~InputTextArea()
{
	delete text;
}

void InputTextArea::draw()
{
	UIUtils::drawRectangle(position, scale, Color(0x888888ff));
	UIUtils::drawRectangle(position + Vector2f(2, 2), scale - Vector2f(4, 4), selected ? Color(0x00aa00ff) : Color(0xaaaaaaff));
	UIUtils::drawRectangle(position + Vector2f(4, 4), scale - Vector2f(8, 8), Color(0x000000ff));

	text->draw();
}

void InputTextArea::handleMouseEvents(Mouse & mouse)
{
	if (mouse.click() && mouseIn(mouse)) {
		selected = true;
	}
	else if (mouse.click()) {
		selected = false;
	}
}

void InputTextArea::handleKeyEvents(Keyboard & keyboard)
{

	if (!selected)
		return;

	int key = keyboard.getCurrentPressed();
	bool shiftHeld = keyboard.modActive(GLFW_MOD_SHIFT);

	if (((key <= 'Z' && key >= 'A') || 
		(key <= '9' && key >= '0') || 
		key == ' ' || key == '-' || key=='_') && str.size() < maxChars) {

		if ((key <= 'Z' && key >= 'A') && !shiftHeld) {
			key = key - 'A' + 'a';
		}
		str += (char)key;
		text->setText(str);
	}
	if (key == GLFW_KEY_BACKSPACE && !str.empty()) {
		str.erase(str.end() - 1);
		text->setText(str);
	}
	if (key == GLFW_KEY_ENTER) {
		selected = false;
	}

	keyboard.clearQueues();


}

std::string & InputTextArea::getString()
{
	return str;
}
