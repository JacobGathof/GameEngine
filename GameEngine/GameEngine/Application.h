#pragma once

#define GL3W_IMPLEMENTATION
#include <iostream>
#include "Color.h"
#include "Window.h"
#include "Screen.h"
#include "ResourceManager.h"
#include "GameTimer.h"
#include "BounceTimer.h"
#include "Player.h"
#include "World.h"
#include "Circle.h"
#include "FollowAi.h"
#include "GoToPointAI.h"
#include "List.h"
#include "GameState.h"
#include "UIManager.h"
#include "RunAwayAI.h"
#include "CircleHitbox.h"
#include "RectHitbox.h"
#include "ComplexHitbox.h"
#include "ComplexPolygon.h"
#include "Rectangle.h"
#include "PlayerCombatAI.h"
#include "Application.h"
#include "CardManager.h"
#include "DeckManager.h"
#include "RoomFactory.h"

class Application
{
public:
	Application();
	~Application();
	void run();

};

