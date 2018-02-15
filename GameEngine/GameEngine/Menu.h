#pragma once
#include "Inventory.h"
#include "SettingsPage.h"

enum class MenuTabType {
	INVENTORY,
	CARDS,
	LEVELING,
	SETTINGS,
};


class MenuTab : public AbstractUIComponent
{
public:
	MenuTab(AbstractUIComponent * comp, Vector2f& pos, Vector2f& scale);
	~MenuTab();

	virtual void draw();
	virtual void update(float dt);
	virtual void hover(Vector2f& pos);
	virtual void click(Vector2f& pos);
private:
	AbstractUIComponent * tabContents;

};



class Menu : public AbstractUIComponent
{
public:
	Menu();
	~Menu();

	void draw();
	void update(float dt);
	void setCurrentTab(MenuTabType tab);

private:

	MenuTab * tabs[2];
	//AbstractUIComponent * activeComponent;
	//Inventory * inventory;
	//SettingsPage* settings;

	//CardsPage*
	//Armor
	//Weapons
	//LevelUpPage
};

