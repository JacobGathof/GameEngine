#include "stdafx.h"
#include "CppUnitTest.h"
#include "GoToPointAI.h"
#include "LivingObject.h"
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			LivingObject * structure = new LivingObject("Structure", TextureType::TEXTURE_MELODY, Vector2f(-300, -100), Vector2f(256, 256), 100, 100);
			structure->moveSpeed = 600;
			GoToPointAI ai(Vector2f(0,0));
			while (!ai.execute(structure, .016)) {
				std::cerr << structure->pos[1] << std::endl;
			}

			Assert::AreEqual(round(structure->pos[0]), round(0.0f));
			Assert::AreEqual(round(structure->pos[1]), round(0.0f));
		}

	};
}