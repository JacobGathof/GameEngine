#include "UIManager.h"
#include "Menu.h"
#include "Textbox.h"
#include "Statusbar.h"
#include "Banner.h"
#include "EnemyStatusbar.h"
#include "QuoteBanner.h"
#include "CommandLine.h"
#include "PauseMenu.h"

#include "GameState.h"

Textbox* UIManager::textbox;
Menu* UIManager::menu;
Banner* UIManager::banner;
QuoteBanner* UIManager::quoteBanner;
Statusbar* UIManager::statusbar;
EnemyStatusbar* UIManager::enemyStatus;
CommandLine* UIManager::cmdLine;
PauseMenu* UIManager::pauseMenu;

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
	quoteBanner->draw();
	statusbar->draw();
	enemyStatus->draw();
	cmdLine->draw();

	if (GameState::isGamePaused()) {
		pauseMenu->draw();
	}
}

void UIManager::init()
{
	textbox = new Textbox();
	menu = new Menu();
	banner = new Banner();
	quoteBanner = new QuoteBanner();
	statusbar = new Statusbar();
	enemyStatus = new EnemyStatusbar();
	cmdLine = new CommandLine();
	pauseMenu = new PauseMenu();

	statusbar->setVisible(true);
	//menu->setVisible(true);
	//addText(std::string("Hello World"), std::string("--------"), TextureType::TEXTURE_PANDORA);

}

void UIManager::clean()
{
	delete textbox;
	delete menu;
	delete banner;
	delete quoteBanner;
	delete statusbar;
	delete enemyStatus;
	delete cmdLine;
	delete pauseMenu;
}

void UIManager::update(float dt)
{
	if (!GameState::isGamePaused()) {
		textbox->update(dt);
		menu->update(dt);
		banner->update(dt);
		quoteBanner->update(dt);
		statusbar->update(dt);
		enemyStatus->update(dt);
		cmdLine->update(dt);
	}
}

void UIManager::resize(int newX, int newY)
{
	menu->resize(newX, newY);
	textbox->resize(newX, newY);
	banner->resize(newX,newY);
	quoteBanner->resize(newX, newY);
	statusbar->resize(newX,newY);
	enemyStatus->resize(newX, newY);
	cmdLine->resize(newX, newY);
}

void UIManager::handleMouseEvents(Mouse & mouse)
{
	if (!GameState::isGamePaused()) {
		menu->handleMouseEvents(mouse);
		textbox->handleMouseEvents(mouse);
	}
	else {
		pauseMenu->handleMouseEvents(mouse);
	}
}

void UIManager::handleKeyboardEvents(Keyboard & keyboard)
{
	if (!GameState::isGamePaused()) {
		cmdLine->handleKeyEvents(keyboard);
		menu->handleKeyEvents(keyboard);
		textbox->handleKeyEvents(keyboard);
	}
}



void UIManager::addText(std::string& text)
{
	textbox->addPlainTextToQueue(text);
}

void UIManager::addText(std::string & text, std::string & name, TextureType tex)
{
	textbox->addDialogueToQueue(text, name, tex);
}

void UIManager::addChoice(List<std::string>& text)
{
	textbox->addChoiceToQueue(text);
}

void UIManager::toggleMenu()
{
	menu->toggle();
}

void UIManager::setEnemyStatusVisible(bool t)
{
	enemyStatus->setVisible(t);
}

void UIManager::setStatusVisible(bool t)
{
	statusbar->setVisible(t);
}

void UIManager::toggleCommandLine()
{
	cmdLine->toggle();
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

void UIManager::setQuoteText(std::string & str)
{
	quoteBanner->setText(str);
}

bool UIManager::isQuoteBannerVisible()
{
	return quoteBanner->isVisible();
}
