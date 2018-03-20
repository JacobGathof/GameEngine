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

};

