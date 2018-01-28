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

private:
	static float width;
	static float height;
	static float scrollMultiplier;
	static ShaderType worldShaders[];


	static void updateShaders();
};

