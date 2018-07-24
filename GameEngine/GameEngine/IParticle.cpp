#include "IParticle.h"
#include "ResourceManager.h"


IParticle::IParticle(ParticleData& data){
	position = data.position;
	velocity = data.velocity;
	color = data.primaryColor;
	life = data.life;
	maxLife = life;
}

IParticle::~IParticle(){}

void IParticle::update(float dt){
	position += dt * velocity;
	life -= dt;
	color[3] = max(0, life / maxLife);
}



SimpleParticle::SimpleParticle(ParticleData& data) : IParticle(data) {
	
}

void SimpleParticle::update(float dt){
	IParticle::update(dt);
}

void SimpleParticle::draw()
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
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
}

void LightParticle::update(float dt)
{
	IParticle::update(dt);
}

void LightParticle::draw()
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	ShaderProgram* p = Res::get(ShaderType::LIGHT_SHADER);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);

	m->bind();

	p->bind();
	p->loadVector2f("translate", position);
	p->loadVector2f("scale", Vector2f(16, 16));
	p->loadColor("color", color);

	m->draw();
}




TexturedParticle::TexturedParticle(ParticleData & data) : IParticle(data)
{
	tex = data.tex;
}

void TexturedParticle::update(float dt)
{
	IParticle::update(dt);
}

void TexturedParticle::draw()
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	ShaderProgram* p = Res::get(ShaderType::ANIMATED_SHADER);
	Res::get(tex)->bind();
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);

	m->bind();

	p->bind();
	p->loadVector2f("translate", position);
	p->loadVector2f("scale", Vector2f(32, 32));
	p->loadColor("color", color);

	p->loadInteger("rows", 1);
	p->loadInteger("columns", 1);
	p->loadInteger("currentRow", 0);
	p->loadInteger("currentColumn", 0);

	m->draw();
}
