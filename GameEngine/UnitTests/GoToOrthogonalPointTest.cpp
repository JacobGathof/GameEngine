#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameEngine/GoToOrthogonalPointAI.h"
#include "../GameEngine/TextureManager.h"
#include "../GameEngine/LivingObject.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(GoToOrthogonalPointAITests)
	{
	public:

		TEST_METHOD(YFirst)
		{
			GoToOrthogonalPointAI ai(Vector2f(100, 100), true);
			LivingObject obj("me", TextureType::SWORD_ICON, Vector2f(0, 0), Vector2f(10, 10), 0, 0);
			obj.moveSpeed = 10;

			while (!ai.done) {
				ai.execute(&obj, 1.0f);
			}

			Assert::AreEqual((int)obj.pos[1], 100);

			while (!ai.execute(&obj, 1.0f));

			Assert::AreEqual((int)obj.pos[0], 100);
			Assert::AreEqual((int)obj.pos[1], 100);
		}

		TEST_METHOD(XFirst)
		{
			GoToOrthogonalPointAI ai(Vector2f(100, 100), false);
			LivingObject obj("me", TextureType::SWORD_ICON, Vector2f(0, 0), Vector2f(10, 10), 0, 0);
			obj.moveSpeed = 10;

			while (!ai.done) {
				ai.execute(&obj, 1.0f);
			}

			Assert::AreEqual((int)obj.pos[0], 100);

			while (!ai.execute(&obj, 1.0f));

			Assert::AreEqual((int)obj.pos[0], 100);
			Assert::AreEqual((int)obj.pos[1], 100);
		}

	};
}