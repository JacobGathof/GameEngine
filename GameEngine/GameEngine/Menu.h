#pragma once
#include "InventoryPage.h"
#include "SettingsPage.h"
#include "Timer.h"

enum class MenuTabType {
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
	virtual void handleMouseEvents(Mouse& mouse);

private:
	//AbstractUIComponent * activeComponent;
	InventoryPage * inventory;
	SettingsPage * settings;

	//CardsPage*
	//Armor
	//Weapons
	//LevelUpPage
};

