#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameEngine/RunAwayAI.h"
#include "../GameEngine/TextureManager.h"
#include "../GameEngine/LivingObject.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(RunAwayAITests)
	{
	public:

		TEST_METHOD(RunAwayFar)
		{
			LivingObject obj("me", TextureType::SWORD_ICON, Vector2f(1000, 1000), Vector2f(10, 10), 0, 0);
			RunAwayAI ai(&obj);
			LivingObject obj2("me", TextureType::SWORD_ICON, Vector2f(0, 0), Vector2f(10, 10), 0, 0);
			obj2.moveSpeed = 10;

			int dist1 = obj.pos.distanceTo(obj2.pos);
			ai.execute(&obj2, 1.0f);
			int dist2 = obj.pos.distanceTo(obj2.pos);

			Assert::IsTrue(dist1 == dist2);
		}

		TEST_METHOD(RunAwayClose)
		{
			LivingObject obj("me", TextureType::SWORD_ICON, Vector2f(10, 10), Vector2f(10, 10), 0, 0);
			RunAwayAI ai(&obj);
			LivingObject obj2("me", TextureType::SWORD_ICON, Vector2f(0, 0), Vector2f(10, 10), 0, 0);
			obj2.moveSpeed = 10;

			int dist1 = obj.pos.distanceTo(obj2.pos);
			ai.execute(&obj2, 1.0f);
			int dist2 = obj.pos.distanceTo(obj2.pos);

			Assert::IsTrue(dist1 < dist2);
		}

	};
}