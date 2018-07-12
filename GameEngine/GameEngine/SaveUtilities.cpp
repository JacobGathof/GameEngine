#include "SaveUtilities.h"
#include "GameState.h"
#include <fstream>

List<int*> SaveUtilities::integerSaves;
List<float*> SaveUtilities::floatSaves;
List<std::string*> SaveUtilities::stringSaves;

void SaveUtilities::saveGame()
{
	std::ofstream file;
	std::string str;
	file.open("res/save.txt", file.out);

	for (auto i : integerSaves) {
		file << std::to_string(*i).c_str() << std::endl;
	}
	for (auto f : floatSaves) {
		file << std::to_string(*f).c_str() << std::endl;
	}
	for (auto c : stringSaves) {
		file << *c << std::endl;
	}

	file.close();

}

void SaveUtilities::loadGame()
{

	std::ifstream file;
	std::string str;
	file.open("res/save.txt", file.in);

	for (auto i : integerSaves) {
		if (!file) continue;
		std::getline(file, str);
		*i = std::atoi(str.c_str());
	}
	for (auto f : floatSaves) {
		if (!file) continue;
		std::getline(file, str);
		*f = std::atof(str.c_str());
	}
	for (auto c : stringSaves) {
		if (!file) continue;
		std::getline(file, str);
		*c = str;
	}

	file.close();

	std::cout << "Finished Loading" << std::endl;
}

void SaveUtilities::init()
{
	integerSaves.add(&GameState::choicePointer);
	floatSaves.add(&GameState::sliderValue);
	floatSaves.add(&GameState::red);
	floatSaves.add(&GameState::green);
	floatSaves.add(&GameState::blue);
	stringSaves.add(&GameState::playerName);
}
