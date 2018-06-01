#include "Renderer.h"
#include "UIManager.h"
#include "World.h"
#include "GameState.h"
#include "WeatherManager.h"

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

void Renderer::draw()
{

	
	drawWorld();
	drawUI();
	drawEffects();

	postProcess();
	

}

void Renderer::drawWorld()
{
	Framebuffer* buf = Res::get(FramebufferType::WORLD_BUFFER);
	buf->bind();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	World::getInstance()->drawTerrain();
	World::getInstance()->drawObjects();
	World::getInstance()->drawHitboxes();
	//World::getInstance()->draw();
}


void Renderer::drawEffects()
{
	Framebuffer* buf = Res::get(FramebufferType::PARTICLES_BUFFER);
	buf->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	World::getInstance()->drawEffects();
	WeatherManager::drawWeatherEffects();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	buf = Res::get(FramebufferType::LIGHT_BUFFER);
	buf->bind();
	Color c = WeatherManager::currentLight;
	glClearColor(c[0], c[1], c[2], c[3]);
	//glClearColor(.5,.5,.5,.5);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	World::getInstance()->drawLights();
	glClearColor(0,0,0,0);
}

void Renderer::drawUI()
{
	glBlendFunc(GL_ONE, GL_ZERO);
	Framebuffer* buf = Res::get(FramebufferType::UI_BUFFER);
	buf->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	UIManager::draw();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void Renderer::postProcess()
{
	glBlendFunc(GL_ONE, GL_ZERO);
	Framebuffer* buf = Res::get(FramebufferType::DEFAULT);
	buf->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	ShaderProgram * sp = Res::get(ShaderType::POST_PROCESS_SHADER);
	m->bind();
	sp->bind();
	sp->loadInteger("ui", 0);
	sp->loadInteger("world", 1);
	sp->loadInteger("particles", 2);
	sp->loadInteger("lights", 3);

	sp->loadFloat("ui_trans", GameState::sliderValue);
	sp->loadFloat("ui_blue", GameState::ui_blue);

	sp->loadColor("screen_color", Screen::screenColor);
	sp->loadFloat("screen_color_percent", Screen::screenColorPercent);

	Res::get(FramebufferType::UI_BUFFER)->bindTexture(0);
	Res::get(FramebufferType::WORLD_BUFFER)->bindTexture(1);
	Res::get(FramebufferType::PARTICLES_BUFFER)->bindTexture(2);
	Res::get(FramebufferType::LIGHT_BUFFER)->bindTexture(3);
	m->draw();


	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}
