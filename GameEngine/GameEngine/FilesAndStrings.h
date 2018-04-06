#pragma once

#include "List.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class FilesAndStrings
{
public:
	FilesAndStrings();
	~FilesAndStrings();

	static List<std::string> getFileContents(std::string& filename);
	static List<std::string> parseStrings(std::string& line, char regex);
	static List<int> parseInts(std::string& line, char regex);
	static List<float> parseFloats(std::string& line, char regex);
	static int parseInt(std::string& line);
	static float parseFloat(std::string& line);
};

