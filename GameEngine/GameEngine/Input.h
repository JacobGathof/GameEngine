#pragma once
#include <map>
#include <vector>
#include "PlayerAI.h"
#include "Mouse.h"
#include "Keyboard.h"

class Input
{
public:

	Input();
	~Input();

	static PlayerAI * ai;

	static Mouse mouse;
	static Keyboard keyboard;

	static void processInput(float dt);
	static void feedKey(int key, int state);
	static void init();
	static void feedMousePosition(Vector2f& pos);
	static void feedMouseEvent(int button, int action);
	

private:


};

