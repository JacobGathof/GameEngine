#include "Menu.h"

#include "InventoryPage.h"
#include "SettingsPage.h"
#include "CardsPage.h"

Menu::Menu()
{
	settings = new SettingsPage();
	cardsPage = new CardsPage();
}

Menu::~Menu()
{
	delete settings;
	delete cardsPage;
}

void Menu::draw()
{
	if (!visible)
		return;

	settings->draw();
	cardsPage->draw();

}

void Menu::update(float dt)
{
	if (!visible)
		return;

	settings->update(dt);
	cardsPage->update(dt);
}

void Menu::handleMouseEvents(Mouse & mouse)
{
	if (!visible)
		return;

	settings->handleMouseEvents(mouse);
	cardsPage->handleMouseEvents(mouse);
}

void Menu::handleKeyEvents(Keyboard & keyboard)
{
	if (!visible)
		return;

	settings->handleKeyEvents(keyboard);
	cardsPage->handleKeyEvents(keyboard);
}

void Menu::toggle()
{
	visible = !visible;
}
