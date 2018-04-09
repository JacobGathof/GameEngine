#include "stdafx.h"
#include "CppUnitTest.h"
#include "../GameEngine/FilesAndStrings.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(FileAndStringTests)
	{
	public:

		TEST_METHOD(ReadFile)
		{
			List<std::string> lines = FilesAndStrings::getFileContents(std::string("../GameEngine/ObjectMaps/Clearing"));

			Assert::AreEqual(lines.get(0), std::string("LARGE_TREE 1544.6180555555557 903.2327586206897 1200.0 1200.0 Rect -20 -350 400.0 350.0"));
			Assert::AreEqual(lines.size(), 88);
		}

		TEST_METHOD(ParseInt)
		{
			Assert::AreEqual(0, FilesAndStrings::parseInt(std::string("0")));

			Assert::AreEqual(5, FilesAndStrings::parseInt(std::string("5.6")));
		}

		TEST_METHOD(ParseFloat)
		{
			Assert::AreEqual(0.0f, FilesAndStrings::parseFloat(std::string("0")));

			Assert::AreEqual(5.6f, FilesAndStrings::parseFloat(std::string("5.6")));
		}

		TEST_METHOD(ParseFloats)
		{
			List<float> values = FilesAndStrings::parseFloats(std::string("1 2.3 3 4"), ' ');
			List<float> answers;
			answers.add(1.0f);
			answers.add(2.3f);
			answers.add(3.0f);
			answers.add(4.0f);

			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(values[i], answers[i]);
			}

			values = FilesAndStrings::parseFloats(std::string("1,2.3,3,4"), ',');
			answers.clear();
			answers.add(1.0f);
			answers.add(2.3f);
			answers.add(3.0f);
			answers.add(4.0f);

			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(values[i], answers[i]);
			}
		}

		TEST_METHOD(ParseIntsTest)
		{
			List<int> values = FilesAndStrings::parseInts(std::string("1 2.3 3 4"), ' ');
			List<int> answers;
			answers.add(1);
			answers.add(2);
			answers.add(3);
			answers.add(4);

			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(values[i], answers[i]);
			}

			values = FilesAndStrings::parseInts(std::string("1,2.3,3,4"), ',');
			answers.clear();
			answers.add(1);
			answers.add(2);
			answers.add(3);
			answers.add(4);

			for (int i = 0; i < 4; i++) {
				Assert::AreEqual(values[i], answers[i]);
			}
		}



	};
}