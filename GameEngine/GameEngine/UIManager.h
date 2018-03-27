#pragma once
#include "AbstractUIComponent.h"
#include "List.h"

class Textbox;
class Menu;
class Banner;
class Statusbar;

class UIManager
{
public:
	UIManager();
	~UIManager();

	static void draw();
	static void init();
	static void clean();
	static void update(float dt);
	static void resize(int newX, int newY);
	static void handleMouseEvents(Mouse& mouse);
	static void handleKeyboardEvents(Keyboard& keyboard);

	static void addText(std::string& text);
	static void addChoice(List<std::string>& text);
	static void toggleMenu();
	static bool isTextboxEmpty();


	static bool playBannerAnimation(float dt);
	static void setBannerText(std::string& str, std::string& str_sub);
	static bool isBannerVisible();

private:
	static Textbox * textbox;
	static Menu * menu;
	static Banner * banner;
	static Statusbar * statusbar;

};

