#pragma once
#include "ResourceManager.h"
#include "Screen.h"

class Statusbar
{
public:
	Statusbar();
	~Statusbar();
	void draw();
	void update(float dt);

private:
	Vector2f position;

	Vector2f topLeft = Vector2f(600, 790);
	Vector2f botRight = Vector2f(790, 100);
};

