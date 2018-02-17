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
	virtual void hover(Vector2f& pos);
	virtual void click(Vector2f& pos);
	virtual void release(Vector2f& pos);

private:
	//AbstractUIComponent * activeComponent;
	InventoryPage * inventory;
	SettingsPage * settings;

	//CardsPage*
	//Armor
	//Weapons
	//LevelUpPage
};

