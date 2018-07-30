#pragma once
#include "AbstractUIComponent.h"
#include "Timer.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "List.h"
#include "Text.h"

class InventoryPage;
class CardsPage;
class SettingsPage;
class EquipPage;

enum class MenuTabType {
	INVENTORY,
	CARDS,
	LEVELING,
	SETTINGS,
	WEAPONS,
};

class MenuTab : public AbstractUIComponent {
public:

	MenuTab(AbstractUIComponent* a, std::string& str, Vector2f& pos, Vector2f& scale);
	~MenuTab();
	virtual void draw();
	virtual void resize(int x, int y);
	bool clicked(Mouse& mouse);

	void setActive(bool b);

	AbstractUIComponent* getContent();
private:
	Text * tabText;
	AbstractUIComponent * content;
	bool active = false;

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
	AbstractUIComponent * activeComponent;
	MenuTab* activeTab;

	InventoryPage * inventory;
	CardsPage * cardsPage;
	SettingsPage * settings;
	EquipPage * equipPage;

	Vector2f tab_o = Vector2f(100, 0);
	Vector2f tab_s = Vector2f(100, 100);
	Vector2f tab_area = Vector2f(100, 600);


	Vector2f basePos = Vector2f(100, 250);
	Vector2f baseScale = Vector2f(600, 400);


	List<MenuTab*> tabs;

	//CardsPage*
	//Armor
	//Weapons
	//LevelUpPage
};

