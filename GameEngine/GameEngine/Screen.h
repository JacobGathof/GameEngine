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
	static void updateUniforms();
	static Vector2f toScreenCoords(Vector2f translate);
	static Vector2f toScreenCoordsUI(Vector2f translate);
	static Vector2f toScreenScale(Vector2f scale);
	static Vector2f fromScreenToUISpace(Vector2f pos);
	static void moveTo(Vector2f pos);

	static void follow(Vector2f playerPos);

	static Color screenColor;
	static float screenColorPercent;

	static float width;
	static float height;
	static Vector2f offset;

private:
	static float scrollMultiplier;
};

