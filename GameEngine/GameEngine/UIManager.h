#pragma once
#include "Menu.h"
#include "Textbox.h"
#include "StatsPage.h"
#include "Statusbar.h"
#include "Inventory.h"

class UIManager
{
public:
	UIManager();
	~UIManager();

	static void draw();
	static void init();
	static void clean();
	static void update(float dt);
	static void hover(Vector2f& pos);
	static void click(Vector2f& pos);
	static void addText(std::string text);
	static void setMenuTab(MenuTabType tab);

private:
	static Textbox * textbox;
	static Menu * menu;

};

