#pragma once
#include "ResourceManager.h"
#include "List.h"
#include "Object.h"
#include "FilesAndStrings.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <map>

struct TerrainTile {
	int row;
	int column;
};


class TerrainMap
{
public:
	TerrainMap();
	~TerrainMap();

	List<List<TerrainTile>> tiles;
	void draw(Object * player);
	void update(float dt);
	void constructMap(std::string filename);

	int width = 0;
	int height = 0;

	std::map<int, TextureType> valuesMap;

};

