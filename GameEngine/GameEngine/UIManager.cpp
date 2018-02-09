#include "UIManager.h"


Textbox* UIManager::textbox;
StatsPage* UIManager::page;
Statusbar* UIManager::status;
Inventory* UIManager::inventory;

UIManager::UIManager()
{
}


UIManager::~UIManager()
{
}

void UIManager::draw()
{
	textbox->draw();
	//page->draw();
	//status->draw();
	inventory->draw();
}

void UIManager::init()
{
	textbox = new Textbox();
	page = new StatsPage();
	status = new Statusbar();
	inventory = new Inventory();
}

void UIManager::clean()
{
	delete textbox;
	delete page;
	delete status;
	delete inventory;
}

void UIManager::update(float dt)
{
	textbox->update(dt);
	page->update(dt);
	status->update(dt);
	inventory->update(dt);
}

void UIManager::hover(Vector2f & pos)
{
	status->hover(pos);
	inventory->hover(pos);
}

void UIManager::click(Vector2f & pos)
{
	inventory->click(pos);
}
