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
	float xOffset = tiles.size() / 2;
	float yOffset = tiles.get(0).size() / 2;
	float xLoc = (player->pos[0] / 100) + (tiles.size()/2);
	float yLoc = -(player->pos[1] / 100) + (tiles.get(0).size()/2);
	int offset = 10;
	
	for (int i = yLoc - offset; (i < yLoc + offset) && (i < tiles.get(0).size()); i++) {
		for (int k = xLoc - offset; (k < xLoc + offset) && (k < tiles.size()); k++) {
			if (i < 0 || k < 0) {
				continue;
			}
			Res::get(TextureType::TERRAIN_SHEET)->bind();
			TerrainTile tile = tiles.get(i).get(k);
			shader->loadVector2f("translate", Vector2f(100 * (k - xOffset), 100 * (yOffset - i)));
			shader->loadVector2f("scale", Vector2f(100, 100));

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
		List<int> dim = parseInts(in);
		width = dim.get(0);
		height = dim.get(1);
		for (int i = 0; i < width; i++) {
			List<TerrainTile> ts;
			
			for (int k = 0; k < height; k++) {
				if (!std::getline(file, in)) {
					std::cout << "Exitting Early" << std::endl;
					return;
				}
				dim = parseInts(in);
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

List<int> TerrainMap::parseInts(std::string str)
{
	List<int> vals;
	std::string current = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			std::stringstream stream(current);
			int val;
			stream >> val;
			vals.add(val);
			current = "";
		}
		else {
			current += str[i];
		}
	}
	if (current != "") {
		std::stringstream stream(current);
		int val;
		stream >> val;
		vals.add(val);
		current = "";
	}

	return vals;
}


