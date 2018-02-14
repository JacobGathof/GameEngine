#pragma once
#include "Inventory.h"

class Menu : public AbstractUIComponent
{
public:
	Menu();
	~Menu();

	void draw();
	void update(float dt);

private:

	void drawTabs();

	Inventory * inventory;
	Vector2f position;

	//Settings* settings;
	//CardsPage*
	//Armor
	//Weapons
	//LevelUpPage
};

