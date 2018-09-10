#include "UIManager.h"
#include "Menu.h"
#include "Textbox.h"
#include "Statusbar.h"
#include "Banner.h"
#include "EnemyStatusbar.h"
#include "QuoteBanner.h"
#include "CommandLine.h"
#include "PauseMenu.h"
#include "Map.h"
#include "InputNamePage.h"
#include "ShopWindow.h"

#include "GameState.h"
#include "Item.h"

Textbox* UIManager::textbox;
Menu* UIManager::menu;
Banner* UIManager::banner;
QuoteBanner* UIManager::quoteBanner;
Statusbar* UIManager::statusbar;
EnemyStatusbar* UIManager::enemyStatus;
CommandLine* UIManager::cmdLine;
PauseMenu* UIManager::pauseMenu;
Map* UIManager::map;
InputNamePage* UIManager::inputName;
ShopWindow* UIManager::shopWindow;

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
	//map->draw();
	inputName->draw();
	shopWindow->draw();

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
	map = new Map();
	inputName = new InputNamePage();
	shopWindow = new ShopWindow();

	statusbar->setVisible(true);
	shopWindow->setVisible(true);
	//inputName->setVisible(true);
	enemyStatus->setVisible(true);
	//menu->setVisible(true);
	//addText(std::string("Hello world"), std::string("--------"), TextureType::TEXTURE_PANDORA);
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
	delete map;
	delete inputName;
	delete shopWindow;
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
		map->update(dt);
		inputName->update(dt);
		shopWindow->update(dt);
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
		map->handleMouseEvents(mouse);
		inputName->handleMouseEvents(mouse);
		shopWindow->handleMouseEvents(mouse);
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
		map->handleKeyEvents(keyboard);
		inputName->handleKeyEvents(keyboard);
	}
}



void UIManager::addText(TextboxContentData & data)
{
	textbox->addText(data);
}

void UIManager::addText(std::string& text)
{
	TextboxContentData data;
	data.text = text;
	textbox->addText(data);
}

void UIManager::addText(std::string & text, std::string & name, TextureType tex)
{
	TextboxContentData data;
	data.text = text;
	data.name = name;
	data.portrait = tex;
	data.dialogue = true;
	textbox->addText(data);
}

void UIManager::addText(std::string & text, std::string & name, TextureType tex, Vector2f & imageOffset)
{
	TextboxContentData data;
	data.text = text;
	data.name = name;
	data.portrait = tex;
	data.offset = imageOffset;
	data.dialogue = true;
	textbox->addText(data);
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

void UIManager::showShopWindow(Item* i, bool b){
	shopWindow->setItem(i);
	shopWindow->setVisible(b);
}

void UIManager::setStatusBarValues(float * hp, float * stamina, float * lucidium, float * maxHp, float * maxStamina, float * maxLucidium)
{
	statusbar->setHealth(maxHp, hp);
	statusbar->setStamina(maxStamina, stamina);
	statusbar->setMana(maxLucidium, lucidium);
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
