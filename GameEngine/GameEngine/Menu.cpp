#include "Menu.h"



Menu::Menu()
{
	inventory = new Inventory(&position);
	settings = new SettingsPage(&position);
	activeComponent = settings;
}

Menu::~Menu()
{
	delete inventory;
	delete settings;
}

void Menu::draw()
{
	glBlendFunc(GL_ONE, GL_ZERO);
	drawTabs();
	activeComponent->draw();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Menu::update(float dt)
{
	position = Vector2f(400, 150);
	activeComponent->update(dt);
}

void Menu::setCurrentTab(MenuTab tab)
{
	switch (tab) {
		case MenuTab::INVENTORY:	activeComponent = inventory; break;
		case MenuTab::CARDS:		activeComponent = inventory; break;
		case MenuTab::LEVELING:		activeComponent = inventory; break;
		case MenuTab::SETTINGS:		activeComponent = settings;	 break;
	}
}

void Menu::drawTabs()
{
	for (int i = 0; i < 6; i++) {
		UIUtils::drawRectangle(position+Vector2f(20, 720)+Vector2f(i*160,0), Vector2f(150, 150), Color(0x44444444));
		UIUtils::drawRectangle(position+Vector2f(22, 722)+Vector2f(i*160,0), Vector2f(146, 146), Color(0xffffff44));
		UIUtils::drawRectangle(position+Vector2f(24, 724)+Vector2f(i*160,0), Vector2f(142, 142), Color(0x00000044));
	}
}