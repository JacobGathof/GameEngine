#include "Menu.h"



Menu::Menu()
{
	//inventory = new Inventory(&position);
	//settings = new SettingsPage(&position);
	tabs[0] = new MenuTab(new SettingsPage(), Vector2f(0,0), Vector2f(50,50));
	tabs[1] = new MenuTab(new InventoryPage(), Vector2f(0, 0), Vector2f(50, 50));

	for (int i = 0; i < 2; i++) {
		tabs[i]->setParentPosition(&position);
	}
	//tabs[2] = MenuTab(new SettingsPage(), Vector2f(0, 0), Vector2f(50, 50));
	//tabs[3] = MenuTab(new SettingsPage(), Vector2f(0, 0), Vector2f(50, 50));
	//MenuTab tab(new Settings(), );
}

Menu::~Menu()
{
	for (int i = 0; i < 2; i++) {
		delete tabs[i];
	}
}

void Menu::draw()
{
	glBlendFunc(GL_ONE, GL_ZERO);
	tabs[0]->draw();
	//activeComponent->draw();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void Menu::update(float dt)
{
	position = Vector2f(400, 150);
	//activeComponent->update(dt);
}

void Menu::setCurrentTab(MenuTabType tab)
{
	/*
	switch (tab) {
		case MenuTabType::INVENTORY:	activeComponent = inventory; break;
		case MenuTabType::CARDS:		activeComponent = inventory; break;
		case MenuTabType::LEVELING:		activeComponent = inventory; break;
		case MenuTabType::SETTINGS:		activeComponent = settings;	 break;
	}
	*/
}












MenuTab::MenuTab(AbstractUIComponent * comp, Vector2f& pos, Vector2f& sc)
{
	position = pos;
	scale = sc;
	tabContents = comp;
	tabContents->setParentPosition(&position);
}

MenuTab::~MenuTab()
{
	delete tabContents;
}

void MenuTab::draw()
{
	UIUtils::drawRectangle(position + Vector2f(20, 720) + Vector2f(0 * 160, 0), Vector2f(150, 150), Color(0x44444444));
	UIUtils::drawRectangle(position + Vector2f(22, 722) + Vector2f(0 * 160, 0), Vector2f(146, 146), Color(0xffffff44));
	UIUtils::drawRectangle(position + Vector2f(24, 724) + Vector2f(0 * 160, 0), Vector2f(142, 142), Color(0x00000044));
}

void MenuTab::update(float dt)
{
}

void MenuTab::hover(Vector2f & pos)
{
}

void MenuTab::click(Vector2f & pos)
{
}
