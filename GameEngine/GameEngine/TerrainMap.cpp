#include "TerrainMap.h"



TerrainMap::TerrainMap()
{
}


TerrainMap::~TerrainMap()
{
}

void TerrainMap::draw(){
	ShaderProgram* shader = Res::get(ShaderType::TERRAIN_SHADER);
	shader->bind();
	Model* model = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	model->bind();
	Res::get(TextureType::TEXTURE_TEST)->bind();

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			shader->loadVector2f("translate", Vector2f(200*i - 800,200*j - 800));
			shader->loadVector2f("scale", Vector2f(200,200));
			model->draw();
		}
	}
}

void TerrainMap::update(float dt)
{
}

void TerrainMap::constructMap(std::string filename)
{
	List<List<int>> tiles;
	std::string in;
	std::ifstream file; 
	file.open(filename, std::ios::in);
	if (file.is_open()) {
		while (std::getline(file, in)) {
			tiles.add(parseInts(in));
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


