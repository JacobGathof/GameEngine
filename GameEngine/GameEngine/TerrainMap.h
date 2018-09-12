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
	TerrainMap(List<TextureType>& layers);
	~TerrainMap();

	void draw();
	void update(float dt);

	int width = 0;
	int height = 0;

private:
	List<TextureType> layers;
};

