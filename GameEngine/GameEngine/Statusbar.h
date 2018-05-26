#pragma once
#include "AbstractUIComponent.h"

class Text;

class Statusbar : public AbstractUIComponent
{
public:
	Statusbar();
	~Statusbar();
	virtual void draw();
	virtual void update(float dt);
	virtual void resize(int x, int y);

	void updateStats();
	std::string formatStatString(float cur, float max);

private:

	Color backdrop = Color(0x00004488);
	Color healthColor = Color(0xdd2244ff);
	Color staminaColor = Color(0x22dd22ff);
	Color magicColor = Color(0x0044ffff);
	Color boxColor = Color(0x00002288);


	float hpm = 100;
	float hpc = 100;

	float *health_max = &hpm;
	float *health_cur = &hpc;
	float healthPercentage = 1.0;

	float hpml = hpm;
	float hpcl = hpc;




	float minBarLength = .25f;
	float maxBarLength = .5f;

	float barHeight = 12;
	float barPadding = 4;
	float gap = 4;

	float offsetX = 16;
	float offsetY = 16;
	float height = 800;
	float width = 800;

	float boxHeight = 100;
	float boxWidth = 100;
	float boxPadding = 2;


	Vector2f pos_h;
	Vector2f pos_s;
	Vector2f pos_m;
	Vector2f pos_box;

	Vector2f scale_h;
	Vector2f scale_s;
	Vector2f scale_m;
	Vector2f scale_box;


	Text* healthText;
	Text* staminaText;
	Text* manaText;


};

