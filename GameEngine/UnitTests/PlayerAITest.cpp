#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameEngine/PlayerAI.h"
#include "../GameEngine/TextureManager.h"
#include "../GameEngine/Player.h"
#include "../GameEngine/Keyboard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(RunAwayAITests)
	{
	public:

		TEST_METHOD(moveUp)
		{
			PlayerAI * ai = new PlayerAI();
			Player * player = new Player(std::string("me"), TextureType::BLUE_FLOWERS, Vector2f(0, 0), Vector2f(0, 0), ai);
			ai->user = player;
			player->moveSpeed = 10;
			Keyboard keys;
			keys.setKeyState(GLFW_KEY_W, (int)KeyState::DOWN);
			Assert::IsFalse(!keys.down(GLFW_KEY_W));
			ai->receiveInput(keys);
			int y1 = player->pos[1];
			ai->execute(player, 1.0f);
			int y2 = player->pos[1];
			Assert::AreEqual(y1 + 10, y2);
			delete player;
		}

		TEST_METHOD(moveRight)
		{
			PlayerAI * ai = new PlayerAI();
			Player * player = new Player(std::string("me"), TextureType::BLUE_FLOWERS, Vector2f(0, 0), Vector2f(0, 0), ai);
			ai->user = player;
			player->moveSpeed = 10;
			Keyboard keys;
			keys.setKeyState(GLFW_KEY_D, (int)KeyState::DOWN);
			Assert::IsFalse(!keys.down(GLFW_KEY_D));
			ai->receiveInput(keys);
			int x1 = player->pos[0];
			ai->execute(player, 1.0f);
			int x2 = player->pos[0];
			Assert::AreEqual(x1 + 10, x2);
			delete player;
		}

	};
}