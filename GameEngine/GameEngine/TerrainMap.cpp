#include "TerrainMap.h"



TerrainMap::TerrainMap()
{
	


}


TerrainMap::~TerrainMap()
{
}

void TerrainMap::draw(Object * player){
	ShaderProgram* shader = Res::get(ShaderType::TERRAIN_SHADER);
	shader->bind();
	Model* model = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	model->bind();
	float xOffset = tiles.size() / 2.0f;
	float yOffset = tiles.get(0).size() / 2.0f;
	float xLoc = (player->pos[0] / 100.0f) + (tiles.size()/2.0f);
	float yLoc = -(player->pos[1] / 100.0f) + (tiles.get(0).size()/2.0f);
	float offset = 15.0f;
	
	for (int i = yLoc - offset; (i < yLoc + offset) && (i < tiles.get(0).size()); i++) {
		for (int k = xLoc - offset; (k < xLoc + offset) && (k < tiles.size()); k++) {
			if (i < 0 || k < 0) {
				continue;
			}
			Res::get(TextureType::TERRAIN_SHEET)->bind();
			TerrainTile tile = tiles.get(i).get(k);
			shader->loadVector2f("translate", Vector2f(100.0f * (k - xOffset), 100.0f * (yOffset - i)));
			shader->loadVector2f("scale", Vector2f(100.0f, 100.0f));

			shader->loadInteger("rows", 16);
			shader->loadInteger("columns", 16);
			shader->loadInteger("currentRow", tile.row);
			shader->loadInteger("currentColumn", tile.column);

			model->draw();
			
		}
	}
}

void TerrainMap::update(float dt)
{
}

void TerrainMap::constructMap(std::string filename)
{
	std::string in;
	std::ifstream file; 
	file.open(filename, std::ios::in);
	if (file.is_open()) {
		std::getline(file, in);
		List<int> dim = FilesAndStrings::parseInts(in, ' ');
		width = dim.get(0);
		height = dim.get(1);
		for (int i = 0; i < width; i++) {
			List<TerrainTile> ts;
			
			for (int k = 0; k < height; k++) {
				if (!std::getline(file, in)) {
					std::cout << "Exitting Early" << std::endl;
					return;
				}
				dim = FilesAndStrings::parseInts(in, ' ');
				TerrainTile t;
				t.column = dim.get(0);
				t.row = dim.get(1);
				ts.add(t);
			}
			tiles.add(ts);
		}
		file.close();
	}
	else {
		std::cout << "Failed to open file: " << filename << std::endl;
	}
}


