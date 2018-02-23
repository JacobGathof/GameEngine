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


	glBlendFunc(GL_ONE, GL_ZERO);
	buf = Res::get(FramebufferType::UI_BUFFER);
	buf->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	UIManager::draw();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
	buf = Res::get(FramebufferType::DEFAULT);
	buf->bind();
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	ShaderProgram * sp = Res::get(ShaderType::POST_PROCESS_SHADER);
	m->bind();
	sp->bind();
	sp->loadInteger("ui", 0);
	sp->loadFloat("ui_trans", GameState::sliderValue);
	Res::get(FramebufferType::UI_BUFFER)->bindTexture(0);
	m->draw();


}
