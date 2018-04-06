#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameEngine/CollisionUtil.h"
#include "../GameEngine/ComplexHitbox.h"
#include "../GameEngine/CircleHitbox.h"
#include "../GameEngine/RectHitbox.h"
#include "ComplexPolygonTestObj.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(CollisionUtilTests)
	{
	public:

		/*
		ComplexHitbox comp(new ComplexPolygon({ Vector2f(-100,0), Vector2f(100,0), Vector2f(150,100), Vector2f(0,150), Vector2f(-150,100) }), Vector2f(0, 0));
		RectHitbox rect(Rect(Vector2f(0, 0), Vector2f(150, 100)), Vector2f(-10, -90));
		CircleHitbox circ(Circle(Vector2f(0, 0), 100), Vector2f(0, 0));
		*/

		TEST_METHOD(RectRectCollide)
		{
			RectHitbox rect(Rect(Vector2f(100, 50), Vector2f(150, 100)), Vector2f(0, 0));
			RectHitbox rect2(Rect(Vector2f(0, 0), Vector2f(150, 100)), Vector2f(0, 0));

			Assert::IsTrue(CollisionUtil::collide(rect, rect2));
		}

		TEST_METHOD(RectRectNoCollide)
		{
			RectHitbox rect(Rect(Vector2f(180, 0), Vector2f(150, 100)), Vector2f(0, 0));
			RectHitbox rect2(Rect(Vector2f(0, 0), Vector2f(150, 100)), Vector2f(0, 0));

			Assert::IsFalse(CollisionUtil::collide(rect, rect2));
		}

		TEST_METHOD(CircCircCollide)
		{
			CircleHitbox circ(Circle(Vector2f(0, 0), 100), Vector2f(0, 0));
			CircleHitbox circ2(Circle(Vector2f(0, 0), 100), Vector2f(198, 0));

			Assert::IsTrue(CollisionUtil::collide(circ, circ2));
		}

		TEST_METHOD(CircCircNoCollide)
		{
			CircleHitbox circ(Circle(Vector2f(0, 0), 100), Vector2f(0, 0));
			CircleHitbox circ2(Circle(Vector2f(0, 0), 100), Vector2f(202, 0));

			Assert::IsFalse(CollisionUtil::collide(circ, circ2));
		}

		TEST_METHOD(CompCompCollide)
		{
			ComplexHitbox comp(new ComplexPolygonTest({ Vector2f(-100,0), Vector2f(100,0), Vector2f(150,100), Vector2f(0,150), Vector2f(-150,100) }), Vector2f(280, 0));
			ComplexHitbox comp2(new ComplexPolygonTest({ Vector2f(-100,0), Vector2f(100,0), Vector2f(150,100), Vector2f(0,150), Vector2f(-150,100) }), Vector2f(0, 0));

			Assert::IsTrue(CollisionUtil::collide(comp, comp2));
		}

		TEST_METHOD(CompCompNoCollide)
		{
			ComplexHitbox comp(new ComplexPolygonTest({ Vector2f(-100,0), Vector2f(100,0), Vector2f(150,100), Vector2f(0,150), Vector2f(-150,100) }), Vector2f(0, 0));
			ComplexHitbox comp2(new ComplexPolygonTest({ Vector2f(-100,0), Vector2f(100,0), Vector2f(150,100), Vector2f(0,150), Vector2f(-150,100) }), Vector2f(0, 0));

			comp.updatePos(Vector2f(320, 0));
			comp2.updatePos(Vector2f(0, 0));


			Assert::IsFalse(CollisionUtil::collide(comp, comp2));
		}
	};
}