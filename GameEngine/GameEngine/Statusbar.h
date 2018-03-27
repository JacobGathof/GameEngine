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
	virtual void resize(int x, int y);

private:

	Color backdrop = Color(0x00004488);
	Color healthColor = Color(0xdd2244ff);
	Color staminaColor = Color(0x22dd22ff);
	Color magicColor = Color(0x0044ffff);

	float *health_max;
	float *health_cur;

	float minBarLength = .25f;
	float maxBarLength = .5f;

	float barHeight = 12;
	float barPadding = 4;
	float gap = 8;

	float offsetX = 16;
	float offsetY = 16;
	float topOfScreen = 800;
	float width = 800;


	/*
	Color healthColor = Color(0xffffffdd);
	Color staminaColor = Color(0xffffffdd);
	Color magicColor = Color(0xffffffdd);
	*/
};

