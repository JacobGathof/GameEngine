#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameEngine/World.h"
#include "../GameEngine/Room.h"
#include "../GameEngine/MoveAction.h"
#include "../GameEngine/LivingObject.h"
#include "../GameEngine/TextureManager.h"
#include "../GameEngine/WaitAction.h"
#include "../GameEngine/Condition.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(ActionTests)
	{
	public:

		TEST_METHOD(MoveActionTest) {
			LivingObject * living = new LivingObject(std::string("me"), TextureType::BLUE_FLOWERS_2, Vector2f(0,0), Vector2f(0,0), 100, 100);
			living->moveSpeed = 100;
			Room * room = new Room();
			room->addObject(living);

			World::getInstance()->addRoom(std::string("room"),room);
			World::getInstance()->setCurrentRoom(room);

			MoveAction act(std::string("me"), Vector2f(200,200));

			while (!act.run(1.00));

			Assert::AreEqual(200.0f, living->pos[0]);
			Assert::AreEqual(200.0f, living->pos[1]);
		}

		TEST_METHOD(WaitActionTest) {
			WaitAction wait(3.0f);

			int counter = 0;
			while (!wait.run(0.9f)) {
				counter++;
			}

			Assert::AreEqual(3, counter);
		}

		TEST_METHOD(IntConditionPass) {
			IntCondition cond(1, 1);
			Assert::IsTrue(cond.evaluate());
		}

		TEST_METHOD(IntConditionFail) {
			IntCondition cond(1, 2);
			Assert::IsFalse(cond.evaluate());
		}

	};
}