#include "InputNamePage.h"
#include "UIText.h"
#include "InputTextArea.h"


InputNamePage::InputNamePage()
{
	promptText = new UIText(Vector2f(400, 400), std::string("Enter your name"), Vector2f(40, 40), 0);
	area = new InputTextArea(Vector2f(400, 300), Vector2f(300, 50));
}


InputNamePage::~InputNamePage()
{
	delete area;
	delete promptText;
}

void InputNamePage::draw()
{
	if (!visible)
		return;

	area->draw();
	promptText->draw();
}

void InputNamePage::update(float dt)
{
	area->update(dt);
}

void InputNamePage::resize(int x, int y)
{
}

void InputNamePage::handleMouseEvents(Mouse & mouse)
{
	area->handleMouseEvents(mouse);
}

void InputNamePage::handleKeyEvents(Keyboard & keyboard)
{
	area->handleKeyEvents(keyboard);
}
