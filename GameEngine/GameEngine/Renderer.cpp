#include "Renderer.h"
#include "UIManager.h"
#include "World.h"
#include "GameState.h"

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::draw()
{
	Framebuffer* buf = Res::get(FramebufferType::WORLD_BUFFER);
	buf->bind();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	World::getInstance()->drawTerrain();
	World::getInstance()->drawObjects();
	//World::getInstance()->drawHitboxes();
	//World::getInstance()->draw();


	
	glBlendFunc(GL_ONE, GL_ZERO);
	buf = Res::get(FramebufferType::UI_BUFFER);
	buf->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	UIManager::draw();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	

	//glBlendFunc(GL_SRC_ALPHA, GL_DST_ALPHA);
	buf = Res::get(FramebufferType::PARTICLES_BUFFER);
	buf->bind();
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	World::getInstance()->drawEffects();



	glBlendFunc(GL_ONE, GL_ZERO);
	buf = Res::get(FramebufferType::DEFAULT);
	buf->bind();
	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	ShaderProgram * sp = Res::get(ShaderType::POST_PROCESS_SHADER);
	m->bind();
	sp->bind();
	sp->loadInteger("ui", 0);
	sp->loadInteger("world", 1);
	sp->loadInteger("particles", 2);

	sp->loadFloat("ui_trans", GameState::sliderValue);
	sp->loadFloat("ui_blue", GameState::ui_blue);

	sp->loadColor("screen_color", Screen::screenColor);
	sp->loadFloat("screen_color_percent", Screen::screenColorPercent);

	Res::get(FramebufferType::UI_BUFFER)->bindTexture(0);
	Res::get(FramebufferType::WORLD_BUFFER)->bindTexture(1);
	Res::get(FramebufferType::PARTICLES_BUFFER)->bindTexture(2);
	m->draw();
	


}
