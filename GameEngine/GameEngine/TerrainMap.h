#pragma once
#include "ResourceManager.h"

class TerrainMap
{
public:
	TerrainMap();
	~TerrainMap();

	int terrainTiles[8][8];
	void draw();
	void update(float dt);

};

