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
	virtual void handleKeyEvents(Keyboard& keyboard);
	void toggle();

private:
	//AbstractUIComponent * activeComponent;
	InventoryPage * inventory;
	SettingsPage * settings;
	bool visible = false;

	//CardsPage*
	//Armor
	//Weapons
	//LevelUpPage
};

