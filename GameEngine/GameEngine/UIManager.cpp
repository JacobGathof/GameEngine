#include "UIManager.h"


Textbox* UIManager::textbox;
Menu* UIManager::menu;

UIManager::UIManager()
{
}


UIManager::~UIManager()
{
}

void UIManager::draw()
{
	textbox->draw();
	menu->draw();
}

void UIManager::init()
{
	textbox = new Textbox();
	menu = new Menu();
}

void UIManager::clean()
{
	delete textbox;
	delete menu;
}

void UIManager::update(float dt)
{
	textbox->update(dt);
	menu->update(dt);
}

void UIManager::handleMouseEvents(Mouse & mouse)
{
	menu->handleMouseEvents(mouse);
}

void UIManager::addText(std::string text)
{
	textbox->addTextToQueue(text);
}
