#include "UIManager.h"


Textbox* UIManager::textbox;
StatsPage* UIManager::page;
Statusbar* UIManager::status;

UIManager::UIManager()
{
}


UIManager::~UIManager()
{
}

void UIManager::draw()
{
	textbox->draw();
	page->draw();
	status->draw();
}

void UIManager::init()
{
	textbox = new Textbox();
	page = new StatsPage();
	status = new Statusbar();
}

void UIManager::clean()
{
	delete textbox;
	delete page;
	delete status;
}

void UIManager::update(float dt)
{
	textbox->update(dt);
	page->update(dt);
	status->update(dt);
}

void UIManager::hover(Vector2f & pos)
{
	status->hover(pos);
}
