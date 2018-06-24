#pragma once

#include "Room.h"
#include "World.h"
#include "LivingObject.h"
#include "Input.h"
#include "PlayerAI.h"
#include "Player.h"
#include "InteractionObject.h"
#include "TransitionObject.h"
#include "Chest.h"
#include "FollowAI.h"
#include "DeckManager.h"

class RoomFactory
{
public:
	RoomFactory();
	~RoomFactory();

	static void CreateAllRooms();
	static void addWorldObjects();

private:
	static Room* createReadingRoom();
	static Room* createClearing();
	static Room* createEastOfTown();
	static void AddTransitionObjects();
};

