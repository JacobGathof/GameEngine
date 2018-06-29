#pragma once
#include "World.h"
#include "Light.h";

class WorldManipulator
{
public:

	static void process(Mouse& mouse, Keyboard& keyboard, float dt);

private:
	static Object * currentObject;
	static Light* currentEffect;

	static Vector2f pos1;
	static Vector2f pos2;

};

