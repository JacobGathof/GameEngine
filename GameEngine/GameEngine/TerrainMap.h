#pragma once
#include "ResourceManager.h"
#include "List.h"
#include <iostream>
#include <fstream>
#include <ios>
class TerrainMap
{
public:
	TerrainMap();
	~TerrainMap();

	int terrainTiles[8][8];
	void draw();
	void update(float dt);
	void constructMap(std::string filename);
	List<int> parseInts(std::string str);

};

