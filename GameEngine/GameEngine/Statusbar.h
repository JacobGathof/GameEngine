#pragma once
#include "AbstractUIComponent.h"

class Statusbar : public AbstractUIComponent
{
public:
	Statusbar();
	~Statusbar();
	virtual void draw();
	virtual void update(float dt);
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
	float gap = 4;

	float offsetX = 16+100;
	float offsetY = 16;
	float height = 800;
	float width = 800;

	Vector2f pos_h;
	Vector2f pos_s;
	Vector2f pos_m;

	Vector2f scale_h;
	Vector2f scale_s;
	Vector2f scale_m;

};

