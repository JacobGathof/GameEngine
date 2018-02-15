#pragma once
#include "Inventory.h"
#include "SettingsPage.h"

enum class MenuTab {
	INVENTORY,
	CARDS,
	LEVELING,
	SETTINGS,
};

class Menu : public AbstractUIComponent
{
public:
	Menu();
	~Menu();

	void draw();
	void update(float dt);
	void setCurrentTab(MenuTab tab);

private:

	AbstractUIComponent * activeComponent;

	void drawTabs();

	Inventory * inventory;
	SettingsPage* settings;
	Vector2f position;

	//CardsPage*
	//Armor
	//Weapons
	//LevelUpPage
};

