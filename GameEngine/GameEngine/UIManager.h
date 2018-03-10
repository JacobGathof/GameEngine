#pragma once
#include "Menu.h"
#include "Textbox.h"
#include "StatsPage.h"
#include "Statusbar.h"
#include "InventoryPage.h"
#include "Banner.h"

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


	static void showBanner();
	static void hideBanner();
	static void setBannerText(std::string& str, std::string& str_sub);
	static bool isBannerVisible();

private:
	static Textbox * textbox;
	static Menu * menu;
	static Banner * banner;

};

