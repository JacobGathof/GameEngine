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

	UIUtils::drawRectangle(Vector2f(200,300), Vector2f(400, 400), Color(0xffffffff));
	UIUtils::drawRectangle(Vector2f(200, 300) + Vector2f(2,2), Vector2f(396, 396), Color(0x00000000));

	settings->draw();

}

void Menu::update(float dt)
{
	settings->update(dt);
}

void Menu::hover(Vector2f & pos)
{
	settings->hover(pos);
}

void Menu::click(Vector2f & pos)
{
	settings->click(pos);
}

void Menu::release(Vector2f & pos)
{
	settings->release(pos);
}
