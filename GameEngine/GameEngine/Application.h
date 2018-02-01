#pragma once

#define GL3W_IMPLEMENTATION
#include <iostream>
#include "Color.h"
#include "Window.h"
#include "Screen.h"
#include "Textbox.h"
#include "StatsPage.h"
#include "ResourceManager.h"
#include "GameTimer.h"
#include "BounceTimer.h"
#include "ParticleSystem.h"
#include "Player.h"
#include "World.h"
#include "TransitionObject.h"
#include "Circle.h"
#include "FollowAi.h"
#include "GoToPointAI.h"

class Application
{
public:
	Application();
	~Application();
	void run();

};

