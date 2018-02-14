#include "Renderer.h"
#include "UIManager.h"
#include "World.h"


Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::draw()
{
	Framebuffer* buf = Res::get(FramebufferType::DEFAULT);
	buf->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	World::getInstance()->draw();

	buf = Res::get(FramebufferType::UI_BUFFER);
	buf->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	UIManager::draw();


	buf = Res::get(FramebufferType::DEFAULT);
	buf->bind();
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	ShaderProgram * sp = Res::get(ShaderType::POST_PROCESS_SHADER);
	m->bind();
	sp->bind();
	glBindTexture(GL_TEXTURE_2D, Res::get(FramebufferType::UI_BUFFER)->tbo);
	m->draw();


}
