#include "UIManager.h"
#include "Menu.h"
#include "Textbox.h"
#include "Statusbar.h"
#include "Banner.h"
#include "EnemyStatusbar.h"

Textbox* UIManager::textbox;
Menu* UIManager::menu;
Banner* UIManager::banner;
Statusbar* UIManager::statusbar;
EnemyStatusbar* UIManager::enemyStatus;

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
	statusbar->draw();
	enemyStatus->draw();
}

void UIManager::init()
{
	textbox = new Textbox();
	menu = new Menu();
	banner = new Banner();
	statusbar = new Statusbar();
	enemyStatus = new EnemyStatusbar();
}

void UIManager::clean()
{
	delete textbox;
	delete menu;
	delete banner;
	delete statusbar;
	delete enemyStatus;
}

void UIManager::update(float dt)
{
	textbox->update(dt);
	menu->update(dt);
	banner->update(dt);
	statusbar->update(dt);
	enemyStatus->update(dt);
}

void UIManager::resize(int newX, int newY)
{
	menu->resize(newX, newY);
	textbox->resize(newX, newY);
	banner->resize(newX,newY);
	statusbar->resize(newX,newY);
	enemyStatus->resize(newX, newY);
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
