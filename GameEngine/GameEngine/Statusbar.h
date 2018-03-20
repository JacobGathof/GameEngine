#pragma once
#include "AbstractUIComponent.h"

class Statusbar : public AbstractUIComponent
{
public:
	Statusbar();
	~Statusbar();
	virtual void draw();
	virtual void update(float dt);
	virtual void handleMouseEvents(Mouse& mouse);
	virtual void handleKeyEvents(Keyboard& keyboard);

private:

	Color backdrop = Color(0x00004488);
	Color healthColor = Color(0x882244dd);
	Color staminaColor = Color(0x226622dd);
	Color magicColor = Color(0x004488dd);

	/*
	Color healthColor = Color(0xffffffdd);
	Color staminaColor = Color(0xffffffdd);
	Color magicColor = Color(0xffffffdd);
	*/
};

