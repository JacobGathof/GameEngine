#include "Menu.h"



Menu::Menu()
{
	settings = new SettingsPage();
}

Menu::~Menu()
{
	delete settings;
}

void Menu::draw()
{
	if (!visible)
		return;

	UIUtils::drawRectangle(Vector2f(200,300), Vector2f(400, 400), Color(0xffffffff));
	UIUtils::drawRectangle(Vector2f(200, 300) + Vector2f(2,2), Vector2f(396, 396), Color(0x00000000));

	settings->draw();

}

void Menu::update(float dt)
{
	if (!visible)
		return;

	settings->update(dt);
}

void Menu::handleMouseEvents(Mouse & mouse)
{
	if (!visible)
		return;

	settings->handleMouseEvents(mouse);
}

void Menu::handleKeyEvents(Keyboard & keyboard)
{
	if (!visible)
		return;

	settings->handleKeyEvents(keyboard);
}

void Menu::toggle()
{
	visible = !visible;
}
