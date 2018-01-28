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
			shader->loadVector2f("translate", Vector2f(4-i,4-j));
			shader->loadVector2f("scale", Vector2f(1,1));
			model->draw();
		}
	}

}

void TerrainMap::update(float dt)
{
}
