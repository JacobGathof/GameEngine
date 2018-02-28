#pragma once
#include "Menu.h"
#include "Textbox.h"
#include "StatsPage.h"
#include "Statusbar.h"
#include "InventoryPage.h"

class UIManager
{
public:
	UIManager();
	~UIManager();

	static void draw();
	static void init();
	static void clean();
	static void update(float dt);
	static void handleMouseEvents(Mouse& mouse);
	static void handleKeyboardEvents(Keyboard& keyboard);

	static void addText(std::string& text);
	static void addChoice(List<std::string>& text);
	static void toggleMenu();
	static bool isTextboxEmpty();

private:
	static Textbox * textbox;
	static Menu * menu;

};

