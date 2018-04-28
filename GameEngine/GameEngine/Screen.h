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

	static void moveToBehavior(float dt);
	static void followBehavior(float dt);
	static void nullBehavior(float dt);

	static Color screenColor;
	static float screenColorPercent;

	static float width;
	static float height;
	static Vector2f offset;

	static void update(float dt);
	static void setMovementBehavior(void(*fcn)(float dt));
	static void setTargetPosition(Vector2f* vec);
	static void setPosition(Vector2f& pos);

private:
	static float scrollMultiplier;
	static Vector2f* target;
	static void(*behaviorPtr)(float dt);
};

