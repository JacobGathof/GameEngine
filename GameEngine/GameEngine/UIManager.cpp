#include "UIManager.h"


Textbox* UIManager::textbox;
Menu* UIManager::menu;
Banner* UIManager::banner;

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
	banner->draw();
}

void UIManager::init()
{
	textbox = new Textbox();
	menu = new Menu();
	banner = new Banner();
}

void UIManager::clean()
{
	delete textbox;
	delete menu;
	delete banner;
}

void UIManager::update(float dt)
{
	textbox->update(dt);
	menu->update(dt);
	banner->update(dt);
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

void UIManager::addChoice(List<std::string>& text)
{
	textbox->addChoiceToQueue(text);
}

void UIManager::toggleMenu()
{
	menu->toggle();
}

bool UIManager::isTextboxEmpty()
{
	return textbox->isEmpty();
}


bool UIManager::playBannerAnimation(float dt){
	return banner->playAnimation(dt);
}

void UIManager::setBannerText(std::string& str1, std::string& str2)
{
	banner->setText(str1, str2);
}

bool UIManager::isBannerVisible()
{
	return banner->isVisible();
}
