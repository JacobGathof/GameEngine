#pragma once

#define GL3W_IMPLEMENTATION
#include <iostream>
#include "Color.h"
#include "Window.h"
#include "Textbox.h"
#include "ResourceManager.h"
#include "Timer.h"
#include "ParticleSystem.h"
#include "Player.h"
#include "World.h"

class Application
{
public:
	Application();
	~Application();
	void run();

};

