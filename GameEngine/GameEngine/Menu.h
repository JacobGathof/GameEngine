#pragma once
#include "AbstractUIComponent.h"
#include "Timer.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "List.h"

class InventoryPage;
class CardsPage;
class SettingsPage;

enum class MenuTabType {
	INVENTORY,
	CARDS,
	LEVELING,
	SETTINGS,
};

class MenuTab : public AbstractUIComponent {
public:

	MenuTab(AbstractUIComponent* a, TextureType t, Vector2f pos, Vector2f scale);
	virtual void draw();
	virtual void resize(int x, int y);
	bool clicked(Mouse& mouse);

	AbstractUIComponent* getContent();
private:
	TextureType tex;
	AbstractUIComponent * content;

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
	InventoryPage * inventory;
	CardsPage * cardsPage;
	SettingsPage * settings;

	bool visible = false;

	Vector2f tab_o = Vector2f(100, 0);
	Vector2f tab_s = Vector2f(100, 100);
	Vector2f tab_area = Vector2f(100, 600);

	List<MenuTab> tabs;

	//CardsPage*
	//Armor
	//Weapons
	//LevelUpPage
};

