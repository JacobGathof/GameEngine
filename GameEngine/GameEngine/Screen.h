#pragma once
#include "ResourceManager.h"
class Screen
{
public:
	Screen();
	~Screen();

	static void init();
	static void updateRes(float x, float y);
	static void updateScroll(float f);
	static Vector2f toScreenCoords(Vector2f scale);
	static Vector2f toScreenCoordsUI(Vector2f scale);

private:
	static float width;
	static float height;
	static float scrollMultiplier;
	static ShaderType worldShaders[];

};

