#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameEngine/LivingAI.h"
#include "../GameEngine/Card.h"
#include "../GameEngine/Deck.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(DeckTests)
	{
	public:

		TEST_METHOD(DrawTest) {
			Card * c = new Card(std::string("Name"), std::string("Desc"), nullptr);
			Card * c2 = new Card(std::string("Name2"), std::string("Desc"), nullptr);
			Card * c3 = new Card(std::string("Name3"), std::string("Desc"), nullptr);

			Deck deck;
			deck.addCard(c);
			deck.addCard(c2);
			deck.addCard(c3);

			Card * card = deck.draw();
			Assert::AreEqual(card->getName(), c->getName());
		}

		TEST_METHOD(DiscardTest) {
			Card * c = new Card(std::string("Name"), std::string("Desc"), nullptr);
			Card * c2 = new Card(std::string("Name2"), std::string("Desc"), nullptr);
			Card * c3 = new Card(std::string("Name3"), std::string("Desc"), nullptr);

			Deck deck;
			deck.addCard(c);
			deck.addCard(c2);
			deck.addCard(c3);

			deck.draw();
			deck.discardCard(c);



			Card * card = deck.draw();
			Assert::AreNotEqual(card->getName(), c->getName());
			card = deck.draw();
			Assert::AreNotEqual(card->getName(), c->getName());

			deck.reset();
			deck.draw();
			Assert::AreEqual(1, 1);
		}

		TEST_METHOD(ShuffleTest) {
			Card * c = new Card(std::string("Name"), std::string("Desc"), nullptr);
			Card * c2 = new Card(std::string("Name2"), std::string("Desc"), nullptr);
			Card * c3 = new Card(std::string("Name3"), std::string("Desc"), nullptr);

			Deck deck;
			deck.addCard(c);
			deck.addCard(c2);
			deck.addCard(c3);
			deck.shuffle();


			Card * card1 = deck.draw();
			deck.addCard(card1);
			deck.shuffle();

			Card * card2 = deck.draw();
			deck.addCard(card2);
			deck.shuffle();

			Card * card3 = deck.draw();

			bool same = (card1->getName() == card2->getName()) && (card2->getName() == card3->getName());

			Assert::IsFalse(same);
		}

	};
}