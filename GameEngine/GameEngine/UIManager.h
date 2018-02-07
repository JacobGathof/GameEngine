#pragma once
#include "Textbox.h"
#include "StatsPage.h"
#include "Statusbar.h"

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

private:
	static Textbox * textbox;
	static StatsPage * page;
	static Statusbar * status;


};

