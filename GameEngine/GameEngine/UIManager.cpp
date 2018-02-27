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
	textbox->handleMouseEvents(mouse);
}

void UIManager::handleKeyboardEvents(Keyboard & keyboard)
{
	menu->handleKeyEvents(keyboard);
	textbox->handleKeyEvents(keyboard);
}

void UIManager::addText(std::string& text)
{
	textbox->addTextToQueue(text);
}

void UIManager::addChoice(std::string * t, int length)
{
	textbox->addChoiceToQueue(t, length);
}

void UIManager::toggleMenu()
{
	menu->toggle();
}

bool UIManager::isTextboxEmpty()
{
	return textbox->isEmpty();
}
