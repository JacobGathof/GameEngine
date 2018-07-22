#include "IParticle.h"
#include "ResourceManager.h"


IParticle::IParticle(ParticleData& data){}
IParticle::~IParticle(){}



SimpleParticle::SimpleParticle(ParticleData& data) : IParticle(data) {
	position = data.position;
	velocity = data.velocity;
	color = data.primaryColor;
}

void SimpleParticle::update(float dt){
	position += dt * velocity;
}

void SimpleParticle::draw()
{
	ShaderProgram* p = Res::get(ShaderType::ANIMATED_SHADER);
	Res::get(TextureType::T_SOLID_WHITE)->bind();
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);

	m->bind();

	p->bind();
	p->loadVector2f("translate", position);
	p->loadVector2f("scale", Vector2f(16,16));
	p->loadColor("color", color);

	p->loadInteger("rows", 1);
	p->loadInteger("columns", 1);
	p->loadInteger("currentRow", 0);
	p->loadInteger("currentColumn", 0);

	m->draw();
}




LightParticle::LightParticle(ParticleData& data) : IParticle(data)
{
	position = data.position;
	velocity = data.velocity;
	color = data.primaryColor;
}

void LightParticle::update(float dt)
{
	position += dt * velocity;
}

void LightParticle::draw()
{
	ShaderProgram* p = Res::get(ShaderType::LIGHT_SHADER);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);

	m->bind();

	p->bind();
	p->loadVector2f("translate", position);
	p->loadVector2f("scale", Vector2f(16, 16));
	p->loadColor("color", color);

	m->draw();
}
