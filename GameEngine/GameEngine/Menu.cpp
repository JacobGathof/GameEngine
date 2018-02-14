#include "Menu.h"



Menu::Menu()
{
	inventory = new Inventory(&position);
}

Menu::~Menu()
{
	delete inventory;
}

void Menu::draw()
{
	drawTabs();
	inventory->draw();
}

void Menu::update(float dt)
{
	position = Vector2f(400, 150);
	inventory->update(dt);
}

void Menu::drawTabs()
{
	for (int i = 0; i < 6; i++) {
		UIUtils::drawRectangle(position+Vector2f(20, 720)+Vector2f(i*160,0), Vector2f(150, 150), Color(0x44444444));
		UIUtils::drawRectangle(position+Vector2f(22, 722)+Vector2f(i*160,0), Vector2f(146, 146), Color(0xffffff44));
		UIUtils::drawRectangle(position+Vector2f(24, 724)+Vector2f(i*160,0), Vector2f(142, 142), Color(0x00000044));
	}
}