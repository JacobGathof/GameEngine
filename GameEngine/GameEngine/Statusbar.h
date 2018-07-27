#pragma once
#include "AbstractUIComponent.h"
#include "Timer.h"
#include "BezierSpline.h"

class UIText;

class Statusbar : public AbstractUIComponent
{
public:
	Statusbar();
	~Statusbar();
	virtual void draw();
	virtual void update(float dt);
	virtual void resize(int x, int y);

	void setHealth(float* maxHealth, float* currHealth);
	void setStamina(float* maxStamina, float* currStamina);
	void setMana(float* maxMana, float* currMana);

private:

	struct DataContainer {
		std::string name;

		float hpm = 100; //Dummy variables, will be subsitituted for actual player stats
		float hpc = 100;

		float *data_max = &hpm; // Reference to actual HP Max (Player value)
		float *data_cur = &hpc; // Reference to actual HP Current (Player Value)
		float health_lost = 0; // Regulate the speed of HP decrease

		float percentage = 1.0; //Percentage of Health meter to draw
		float percentageShown = 1.0; // Percentage of Health lost to draw 

		float hpml = hpm; // HP Max Last
		float hpcl = hpc; // HP Current Max
		float hpcs = hpc; // HP Current Shown (Shown hp being lost)

		UIText* text;
	};

	DataContainer health, stamina, mana;

	void updateStats(DataContainer& data);
	void updateComponent(DataContainer& data, float dt);

	std::string formatStatString(float cur, float max);

	UIText* goldText;


	Color backdrop = Color(0x000044ff);
	Color healthColor = Color(0xdd2244ff);
	Color healthLostColor = Color(0xdd8888ff);

	Color staminaColor = Color(0x22dd22ff);
	Color staminaLostColor = Color(0xaaddaaff);

	Color manaColor = Color(0x0044ffff);
	Color manaLostColor = Color(0x4488ffff);


	Color boxColor = Color(0x000022ff);
	Color boxOutline = Color(0x8888aaff);


	Timer timer; // Just for testing

	float minBarLength = .25f;
	float maxBarLength = .5f;

	float barHeight = 12;
	float barPadding = 4;
	float gap = 4;

	float offsetX = 8;
	float offsetY = 16;
	float offsetBoxY = 8;


	float boxHeight = 100;
	float boxWidth = 100;
	float boxPadding = 2;


	Vector2f pos_h;
	Vector2f pos_s;
	Vector2f pos_m;
	Vector2f pos_g;
	Vector2f pos_box;

	Vector2f scale_h;
	Vector2f scale_s;
	Vector2f scale_m;
	Vector2f scale_box;


	BezierSpline fadeCurve = BezierSpline(Vector2f(0,0), Vector2f(.42, 0), Vector2f(.58, 1), Vector2f(1, 1)) * 150;
	Timer fadeTimer;
	int fading;

	float fadeTime = 0.5f;
	Vector2f fadePos = Vector2f(0, 0);
	Color fadeColor = Color::White;

};

