#pragma once
#include "AbstractUIComponent.h"
#include "Timer.h"
#include "Mouse.h"
#include "Keyboard.h"

class InventoryPage;
class CardsPage;
class SettingsPage;

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

	virtual void draw();
	virtual void update(float dt);
	virtual void resize(int x, int y);
	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);
	void toggle();

private:
	//AbstractUIComponent * activeComponent;
	InventoryPage * inventory;
	CardsPage * cardsPage;
	SettingsPage * settings;

	bool visible = false;

	//CardsPage*
	//Armor
	//Weapons
	//LevelUpPage
};

