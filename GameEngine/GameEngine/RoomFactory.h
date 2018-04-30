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

class RoomFactory
{
public:
	RoomFactory();
	~RoomFactory();

	static World * world;

	static void CreateAllRooms();

private:
	static void ReadingRoom();
	static void Clearing();
	static void EastOfTown2();
	static void AddTransitionObjects();
};


