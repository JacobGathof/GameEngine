#include "Pulse.h"
#include "Object.h"


Pulse::Pulse()
{
}


Pulse::~Pulse()
{
}

bool Pulse::update(float dt)
{
	size += dt * 100;

	return size < 800;
}

void Pulse::draw()
{
	glBlendFunc(GL_ONE, GL_ZERO);

	ShaderProgram* p = Res::get(ShaderType::TEST_SHADER_2);
	p->bind();
	p->loadVector2f("translate", parent->pos);
	p->loadVector2f("scale", Vector2f(size));
	Res::get(FramebufferType::OBJECT_BUFFER)->bindTexture(0);
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	m->bind();
	m->draw();
}
