#include "GoToOrthogonalPointAITest.h"
#include "stdafx.h"
#include "CppUnitTest.h"
#include "GoToOrthogonalPointAI.h"
#include "LivingObject.h"
#include <math.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTests
{
	TEST_CLASS(OrthogonalTests)
	{
	public:

		TEST_METHOD(TestYThenX)
		{
			LivingObject * structure = new LivingObject("Structure", TextureType::TEXTURE_MELODY, Vector2f(-300, -100), Vector2f(256, 256), 100, 100);
			structure->moveSpeed = 600;
			GoToOrthogonalPointAI ai(Vector2f(0, 0), true);
			while (ai.done == false) {
				ai.execute(structure, .016);
			}

			Assert::AreEqual(round(structure->pos[1]), round(0.0f));

			while (!ai.execute(structure, .016)) {

			}

			Assert::AreEqual(round(structure->pos[0]), round(0.0f));
		}

		TEST_METHOD(TestXThenY)
		{
			LivingObject * structure = new LivingObject("Structure", TextureType::TEXTURE_MELODY, Vector2f(-300, -100), Vector2f(256, 256), 100, 100);
			structure->moveSpeed = 600;
			GoToOrthogonalPointAI ai(Vector2f(0, 0), false);
			while (ai.done == false) {
				ai.execute(structure, .016);
			}

			Assert::AreEqual(round(structure->pos[0]), round(0.0f));

			while (!ai.execute(structure, .016)) {

			}

			Assert::AreEqual(round(structure->pos[1]), round(0.0f));
		}

	};
}
