#pragma once
#include "AbstractUIComponent.h"
#include "Text.h"

class EnemyStatusbar : public AbstractUIComponent
{
public:
	EnemyStatusbar();
	~EnemyStatusbar();
	virtual void draw();
	virtual void update(float dt);
	virtual void resize(int x, int y);

private:

	Text * text;

	Color backdrop = Color(0x00004488);
	Color healthColor = Color(0xdd2244ff);

	float barHeight = 12;
	float barPadding = 4;
	float gap = 4;

	float offsetX = 16;
	float offsetY = 16;
	float height = 800;
	float width = 800;

	Vector2f pos_h;
	Vector2f scale_h;

	Vector2f pos_t;
	Vector2f scale_t;
};
