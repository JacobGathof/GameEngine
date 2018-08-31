#pragma once
#include "List.h"

class SaveUtilities
{
public:
	static void saveGame();
	static void loadGame();

	static void init();

private:
	static List<int*> integerSaves;
	static List<float*> floatSaves;
	static List<std::string*> stringSaves;

	static void writeFloat(std::ofstream& file, float f);
	static void writeInteger(std::ofstream& file, int f);

	static int loadInt(std::ifstream& file);
	static float loadFloat(std::ifstream& file);
};

