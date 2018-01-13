#pragma once

class Input
{
public:
	Input();
	~Input();

	static bool keys[512];

	static void processInput(float dt);
	static void feedKey(int key, int state);
};

