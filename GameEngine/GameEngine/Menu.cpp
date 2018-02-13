#include "Menu.h"



Menu::Menu()
{
	inventory = new Inventory();
}

Menu::~Menu()
{
	delete inventory;
}

void Menu::draw()
{
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	drawTabs();
	//inventory->draw();
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Menu::update(float dt)
{
	inventory->update(dt);
}

void Menu::drawTabs()
{
	for (int i = 0; i < 6; i++) {
		UIUtils::drawRectangle(Vector2f(20, 720)+Vector2f(i*160,0), Vector2f(150, 150), Color(0x44444444));
		UIUtils::drawRectangle(Vector2f(22, 722)+Vector2f(i*160,0), Vector2f(146, 146), Color(0xffffff44));
		UIUtils::drawRectangle(Vector2f(24, 724)+Vector2f(i*160,0), Vector2f(142, 142), Color(0x00000044));
	}
}