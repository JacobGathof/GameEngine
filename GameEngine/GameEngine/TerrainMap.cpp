#include "TerrainMap.h"

#include "Window.h"


TerrainMap::TerrainMap(List<TextureType>& l)
{
	layers = l;
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
	shader->loadVector2f("translate", Vector2f(64*32,64*32));

	Res::get(TextureType::TS_TILESET)->bind(0);

	for (auto a : layers) {

		Res::get(a)->bind(1);
		shader->loadInteger("layer", 0);
		model->draw();

	}

	/*
	ShaderProgram* p = Res::get(ShaderType::WATER_SHADER);
	p->bind();
	p->loadVector2f("translate", Vector2f(64 * 32, 64*32));
	p->loadInteger("skybox", 0);
	p->loadInteger("dispMap", 1);
	p->loadInteger("tileset", 2);
	p->loadInteger("terrain", 3);
	p->loadInteger("objects", 4);

	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	m->bind();

	Res::get(TextureType::TEXTURE_SKYBOX)->bind(0);
	Res::get(TextureType::PERLIN_NOISE)->bind(1);

	Res::get(TextureType::TS_TILESET)->bind(2);

	Res::get(TextureType::TEXTURE_TEST_4)->bind(3);
	Res::get(FramebufferType::EXTRA_BUFFER_1)->bindTexture(4);

	m->draw();
	*/

}

void TerrainMap::update(float dt)
{
}



