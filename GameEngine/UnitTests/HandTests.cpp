#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameEngine/LivingAI.h"
#include "../GameEngine/Card.h"
#include "../GameEngine/Hand.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(HandTests)
	{
	public:

		TEST_METHOD(AddCard) {
			Hand hand;
			hand.setHandSize(1);
			Card c(std::string("Name"), std::string("Desc"), nullptr);

			Assert::IsTrue(hand.addCard(c));
			Assert::IsFalse(hand.addCard(c));
			hand.setHandSize(5);
			Assert::IsTrue(hand.addCard(c));
		}

		TEST_METHOD(RemoveCard) {
			Hand hand;
			hand.setHandSize(1);
			Card c(std::string("Name"), std::string("Desc"), nullptr);

			Assert::IsTrue(hand.addCard(c));
			Assert::IsFalse(hand.addCard(c));
			hand.removeCard(0);
			Assert::IsTrue(hand.addCard(c));
		}

		TEST_METHOD(RemoveBadCard) {
			Hand hand;
			Card c(std::string("Name"), std::string("Desc"), nullptr);

			Assert::IsTrue(hand.addCard(c));
			hand.removeCard(100);
			Assert::AreEqual(1, 1);
		}

	};
}