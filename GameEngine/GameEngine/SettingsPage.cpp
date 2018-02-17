#include "SettingsPage.h"
#include "Window.h"


SettingsPage::SettingsPage()
{
	button.action = new SettingsActionToggleFullscreen();
}


SettingsPage::~SettingsPage()
{
	delete button.action;
}

void SettingsPage::draw()
{
	/*
	Vector2f pos = position;
	if (parentOffset != 0) {
		pos += *parentOffset;
	}
	UIUtils::drawRectangle(Vector2f(20, 20) + pos, Vector2f(80, 80), Color(0xffffffff));
	UIUtils::drawRectangle(Vector2f(22, 22) + pos, Vector2f(76, 76), Color(0x0000ffff));
	UIUtils::drawRectangle(Vector2f(24, 24) + pos, Vector2f(72, 72), Color(0x000000ff));
	*/

	button.draw();

}

void SettingsPage::update(float dt)
{
	button.update(dt);
}

void SettingsPage::hover(Vector2f & pos)
{
	button.hover(pos);
}

void SettingsPage::click(Vector2f & pos)
{
	button.click(pos);
}

void SettingsPage::release(Vector2f & pos)
{
	button.release(pos);
}




SettingsButton::SettingsButton()
{
	position = Vector2f(200, 200);
	scale = Vector2f(50, 50);
}

SettingsButton::~SettingsButton()
{
}

void SettingsButton::draw()
{
	switch (state) {
	case 0: currentColor = defaultColor; break;
	case 1: currentColor = hoverColor; break;
	case 2: currentColor = clickColor; break;
	}
	UIUtils::drawRectangleIcon(position, scale, currentColor, 1.0f);
}

void SettingsButton::update(float dt)
{

}

void SettingsButton::hover(Vector2f & pos)
{
	if (pos.between(position, position + scale)) {
		state = 1;
	}
	else {
		state = 0;
	}
}

void SettingsButton::click(Vector2f & pos)
{
	if (pos.between(position, position + scale)) {
		state = 2;
	}
}

void SettingsButton::release(Vector2f & pos)
{
	if (pos.between(position, position + scale)) {
		action->performAction();
	}
}

void SettingsActionToggleFullscreen::performAction()
{
	Window::toggleFullscreen();
}
