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
