#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameEngine/ComplexPolygon.h"
#include "ComplexPolygonTestObj.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(ActionTests)
	{
	public:

		TEST_METHOD(PolygonVerticesTestNoMove) {
			ComplexPolygonTest poly({ Vector2f(-100,0), Vector2f(100,0), Vector2f(150,100), Vector2f(0,150), Vector2f(-150,100) });
			Assert::AreEqual(poly.getVertices()[0][0], -100.0f);
			Assert::AreEqual(poly.getVertices()[0][1], 0.0f);
		}

		TEST_METHOD(PolygonVerticesTestMove) {
			ComplexPolygonTest poly({ Vector2f(-100,0), Vector2f(100,0), Vector2f(150,100), Vector2f(0,150), Vector2f(-150,100) });
			poly.updatePos(Vector2f(100, 0));
			Assert::AreEqual(poly.getVertices()[0][0], 0.0f);
			Assert::AreEqual(poly.getVertices()[0][1], 0.0f);
		}

	};
}