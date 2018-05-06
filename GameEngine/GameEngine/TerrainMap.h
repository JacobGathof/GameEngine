#pragma once
#include "ResourceManager.h"
#include "List.h"
#include "Object.h"
#include "FilesAndStrings.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <map>

class TerrainMap
{
public:
	TerrainMap();
	~TerrainMap();

	void draw();
	void update(float dt);
	void constructMap(std::string filename);

	int width = 0;
	int height = 0;

};

