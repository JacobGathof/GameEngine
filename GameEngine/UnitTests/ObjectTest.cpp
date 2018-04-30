#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameEngine/Object.h"
#include "../GameEngine/Hitbox.h"
#include "../GameEngine/TextureManager.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(ObjectTests)
	{
	public:

		TEST_METHOD(UpdateHitboxTest) {
			Object * obj = new Object(std::string("name"), TextureType::BLUE_FLOWERS, Vector2f(0, 0), Vector2f(0, 0));
			Hitbox * hit = new Hitbox();

			obj->addHitbox(hit);
			Assert::AreEqual(1, obj->numHitboxes());
			obj->pos = Vector2f(10, 10);
			obj->updateHitbox();
			Assert::AreEqual(10.0f, hit->getPos()[0]);
			Assert::AreEqual(10.0f, hit->getPos()[1]);
		}


	};
}