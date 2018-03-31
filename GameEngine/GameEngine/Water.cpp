#include "Water.h"



Water::Water()
{
}


Water::~Water()
{
}

void Water::draw()
{
	ShaderProgram* p = Res::get(ShaderType::WATER_SHADER);
	p->bind();
	p->loadVector2f("translate", Vector2f(0,1024));
	p->loadVector2f("scale", Vector2f(512,512));
	p->loadInteger("skybox", 0);
	p->loadInteger("world", 1);
	p->loadInteger("dispMap", 2);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	m->bind();
	Res::get(TextureType::TEXTURE_SKYBOX)->bind(0);
	Res::get(FramebufferType::WORLD_BUFFER)->bindTexture(1);
	Res::get(TextureType::PERLIN_NOISE)->bind(2);

	m->draw();
}
