#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameEngine/Object.h"
#include "../GameEngine/RectHitbox.h"
#include "../GameEngine/Rectangle.h"
#include "../GameEngine/TextureManager.h"
#include "../GameEngine/Room.h"
#include "TestRoom.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(RoomTests)
	{
	public:

		TEST_METHOD(RoomCollideTest) {
			Object * obj = new Object(std::string("name"), TextureType::BLUE_FLOWERS, Vector2f(0, 0), Vector2f(0, 0));
			Hitbox * rect = new RectHitbox(Rect(Vector2f(0, 0), Vector2f(150, 100)), Vector2f(-10, -90));
			obj->addHitbox(rect);
			Hitbox * rect2 = new RectHitbox(Rect(Vector2f(0, 0), Vector2f(150, 100)), Vector2f(-10, -90));
			Object * obj2 = new Object(std::string("Name2"), TextureType::BLUE_FLOWERS, Vector2f(0, 0), Vector2f(0, 0));
			obj2->addHitbox(rect2);
			TestRoom room;
			Assert::IsFalse(room.collideTest(obj, obj2));
		}

		TEST_METHOD(RoomSortTest) {
			Object * obj = new Object(std::string("name"), TextureType::BLUE_FLOWERS, Vector2f(0, -100), Vector2f(0, 0));
			Hitbox * rect = new RectHitbox(Rect(Vector2f(0, 0), Vector2f(150, 100)), Vector2f(-10, -90));
			obj->addHitbox(rect);
			Hitbox * rect2 = new RectHitbox(Rect(Vector2f(0, 0), Vector2f(150, 100)), Vector2f(-10, -90));
			Object * obj2 = new Object(std::string("Name2"), TextureType::BLUE_FLOWERS, Vector2f(0, 0), Vector2f(0, 0));
			obj2->addHitbox(rect2);
			TestRoom room;
			room.addObject(obj2);
			room.addObject(obj);
			room.sort();
			List<Object *> objs = room.getObjects();
			Assert::IsTrue(objs.get(0)->name == std::string("Name2"));
		}

	};
}