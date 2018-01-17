#pragma once

#define GL3W_IMPLEMENTATION
#include <iostream>
#include "Color.h"
#include "Window.h"
#include "Textbox.h"
#include "ShaderManager.h"
#include "FontManager.h"
#include "ModelManager.h"
#include "Timer.h"
#include "ParticleSystem.h"

class Application
{
public:
	Application();
	~Application();
	void run();
	void test();

};

