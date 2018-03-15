#pragma once
#include "ResourceManager.h"
#include "List.h"
#include "Object.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <map>

class TerrainMap
{
public:
	TerrainMap();
	~TerrainMap();

	List<List<int>> tiles;
	void draw(Object * player);
	void update(float dt);
	void constructMap(std::string filename);
	List<int> parseInts(std::string str);

	std::map<int, TextureType> valuesMap;

};

