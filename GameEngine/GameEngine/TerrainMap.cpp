#include "TerrainMap.h"

#include "Window.h"

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

	shader->loadInteger("tileset", 0);
	shader->loadInteger("terrain", 1);
	shader->loadVector2f("scale", Vector2f(0, 0));
	shader->loadVector2f("translate", Vector2f(0, 0));

	Res::get(TextureType::TS_TILESET)->bind(0);
	Res::get(TextureType::TEXTURE_TEST)->bind(1);
	model->draw();


	Res::get(TextureType::TEXTURE_TEST_2)->bind(1);
	model->draw();


	Res::get(TextureType::TEXTURE_TEST_3)->bind(1);
	model->draw();

}

void TerrainMap::update(float dt)
{
}

void TerrainMap::constructMap(std::string filename)
{
	
}


