#include "TerrainMap.h"



TerrainMap::TerrainMap()
{
	valuesMap.insert(std::pair<int, TextureType>(68001, TextureType::grass2));
	valuesMap.insert(std::pair<int, TextureType>(68001, TextureType::grass2));
	valuesMap.insert(std::pair<int, TextureType>(68003, TextureType::grass4));
	valuesMap.insert(std::pair<int, TextureType>(68006, TextureType::grass7));
	valuesMap.insert(std::pair<int, TextureType>(68002, TextureType::grass3));
	valuesMap.insert(std::pair<int, TextureType>(68007, TextureType::grass8));
	valuesMap.insert(std::pair<int, TextureType>(68004, TextureType::grass5));
	valuesMap.insert(std::pair<int, TextureType>(68005, TextureType::grass6));
	valuesMap.insert(std::pair<int, TextureType>(68000, TextureType::grass1));
	valuesMap.insert(std::pair<int, TextureType>(68008, TextureType::grass9));
	valuesMap.insert(std::pair<int, TextureType>(87, TextureType::zc_cliffright));
	valuesMap.insert(std::pair<int, TextureType>(93, TextureType::zc_watergrassbottom));
	valuesMap.insert(std::pair<int, TextureType>(97, TextureType::zc_watergrasstopright));
	valuesMap.insert(std::pair<int, TextureType>(99, TextureType::zc_water));
	valuesMap.insert(std::pair<int, TextureType>(94, TextureType::zc_watergrassleft));
	valuesMap.insert(std::pair<int, TextureType>(98, TextureType::zc_watergrasstop));
	valuesMap.insert(std::pair<int, TextureType>(113, TextureType::ze_watergrasstopright));
	valuesMap.insert(std::pair<int, TextureType>(95, TextureType::zc_watergrassright));
	valuesMap.insert(std::pair<int, TextureType>(89, TextureType::zc_clifftopmidback));
	valuesMap.insert(std::pair<int, TextureType>(90, TextureType::zc_clifftoprightback));
	valuesMap.insert(std::pair<int, TextureType>(84, TextureType::zc_cliffmidfront));
	valuesMap.insert(std::pair<int, TextureType>(86, TextureType::zc_cliffmidright));
	valuesMap.insert(std::pair<int, TextureType>(83, TextureType::zc_cliffleftmid));
	valuesMap.insert(std::pair<int, TextureType>(78, TextureType::zc_cliffbottommidback));
	valuesMap.insert(std::pair<int, TextureType>(79, TextureType::zc_cliffbottomrightback));
	valuesMap.insert(std::pair<int, TextureType>(75, TextureType::zb_topLeftGrassDirt));
	valuesMap.insert(std::pair<int, TextureType>(71001, TextureType::grassTop2));
	valuesMap.insert(std::pair<int, TextureType>(71000, TextureType::grassTop1));
	valuesMap.insert(std::pair<int, TextureType>(71002, TextureType::grassTop3));
	valuesMap.insert(std::pair<int, TextureType>(88, TextureType::zc_clifftopleftback));
	valuesMap.insert(std::pair<int, TextureType>(104, TextureType::zd_waterfalltopleft));
	valuesMap.insert(std::pair<int, TextureType>(105, TextureType::zd_waterfalltopright));
	valuesMap.insert(std::pair<int, TextureType>(70002, TextureType::grassLeft3));
	valuesMap.insert(std::pair<int, TextureType>(67000, TextureType::dirt1));
	valuesMap.insert(std::pair<int, TextureType>(67001, TextureType::dirt2));
	valuesMap.insert(std::pair<int, TextureType>(67002, TextureType::dirt3));
	valuesMap.insert(std::pair<int, TextureType>(67005, TextureType::dirt6));
	valuesMap.insert(std::pair<int, TextureType>(67003, TextureType::dirt4));
	valuesMap.insert(std::pair<int, TextureType>(67004, TextureType::dirt5));
	valuesMap.insert(std::pair<int, TextureType>(85, TextureType::zc_cliffmidleft));
	valuesMap.insert(std::pair<int, TextureType>(102, TextureType::zd_waterfallmidleft));
	valuesMap.insert(std::pair<int, TextureType>(103, TextureType::zd_waterfallmiddleright));
	valuesMap.insert(std::pair<int, TextureType>(70000, TextureType::grassLeft1));
	valuesMap.insert(std::pair<int, TextureType>(108, TextureType::ze_dirtgrasstopleft));
	valuesMap.insert(std::pair<int, TextureType>(69000, TextureType::grassBottom1));
	valuesMap.insert(std::pair<int, TextureType>(69001, TextureType::grassBottom2));
	valuesMap.insert(std::pair<int, TextureType>(69002, TextureType::grassBottom3));
	valuesMap.insert(std::pair<int, TextureType>(72001, TextureType::grassRight2));
	valuesMap.insert(std::pair<int, TextureType>(70001, TextureType::grassLeft2));
	valuesMap.insert(std::pair<int, TextureType>(72000, TextureType::grassRight1));
	valuesMap.insert(std::pair<int, TextureType>(77, TextureType::zc_cliffbottomleftback));
	valuesMap.insert(std::pair<int, TextureType>(100, TextureType::zd_waterfallbottomleft));
	valuesMap.insert(std::pair<int, TextureType>(101, TextureType::zd_waterfallbottomright));
	valuesMap.insert(std::pair<int, TextureType>(72002, TextureType::grassRight3));
	valuesMap.insert(std::pair<int, TextureType>(107, TextureType::ze_dirtgrassbottomright));
	valuesMap.insert(std::pair<int, TextureType>(74, TextureType::zb_bottomRightGrassDirt));


}


TerrainMap::~TerrainMap()
{
}

void TerrainMap::draw(Object * player){
	ShaderProgram* shader = Res::get(ShaderType::TERRAIN_SHADER);
	shader->bind();
	Model* model = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	model->bind();
	int xOffset = tiles.size() / 2;
	int yOffset = tiles.get(0).size() / 2;
	int xLoc = (player->pos[0] / 200) + (tiles.size()/2);
	int yLoc = -(player->pos[1] / 200) + (tiles.get(0).size()/2);
	int offset = 10;
	
	for (int i = xLoc - offset; (i < xLoc + offset) && (i < tiles.get(0).size()); i++) {
		for (int j = yLoc - offset; (j < yLoc + offset) && (j < tiles.size()); j++) {
			if (i < 0 || j < 0) {
				continue;
			}
			Res::get(valuesMap.at(tiles.get(j).get(i)))->bind();
			shader->loadVector2f("translate", Vector2f(200 * (i - xOffset), 200 * (yOffset - j)));
			shader->loadVector2f("scale", Vector2f(200, 200));
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
		while (std::getline(file, in)) {
			tiles.add(parseInts(in));
		}
		file.close();
	}
	else {
		std::cout << "Failed to open file: " << filename << std::endl;
	}

	std::cout << tiles.size() << std::endl;
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


