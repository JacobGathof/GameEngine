#pragma once

#define GL3W_IMPLEMENTATION
#include <iostream>
#include "Color.h"
#include "Window.h"
#include "ShaderProgram.h"
#include "Vector2f.h"
#include "Font.h"


class Application
{
public:
	Application();
	~Application();
	void run();
	void test();
};

