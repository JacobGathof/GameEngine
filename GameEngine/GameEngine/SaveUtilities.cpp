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
		writeInteger(file, *i);
	}
	for (auto f : floatSaves) {
		writeFloat(file, *f);
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
		*i = loadInt(file);
	}
	for (auto f : floatSaves) {
		if (!file) continue;
		*f = loadFloat(file);
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
	floatSaves.add(&GameState::volume);
	stringSaves.add(&GameState::playerName);
}

void SaveUtilities::writeFloat(std::ofstream & file, float f){
	char data[4];
	std::memcpy(data, &f, 4);
	file.write(data, 4);
}

void SaveUtilities::writeInteger(std::ofstream & file, int f){
	char data[4];
	std::memcpy(data, &f, 4);
	file.write(data, 4);
}

int SaveUtilities::loadInt(std::ifstream & file)
{
	char data[4];
	int i;
	file.read(data, 4);
	std::memcpy(&i, data, 4);
	return i;
}

float SaveUtilities::loadFloat(std::ifstream & file)
{
	char data[4];
	float f;
	file.read(data, 4);
	std::memcpy(&f, data, 4);
	return f;
}
