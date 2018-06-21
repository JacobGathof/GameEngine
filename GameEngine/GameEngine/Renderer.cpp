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
	preProcess();
	
	drawWorld();
	drawUI();
	drawEffects();

	postProcess();
	

}

void Renderer::drawWorld()
{

	Res::get(FramebufferType::WORLD_BUFFER)->bind();

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	World::getInstance()->drawTerrain();
	World::getInstance()->drawObjects();
	World::getInstance()->drawHitboxes();
	//World::getInstance()->draw();
}


void Renderer::drawEffects()
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	Res::get(FramebufferType::EFFECTS_BUFFER)->bind();
	World::getInstance()->drawEffects();
	//WeatherManager::drawWeatherEffects();

}

void Renderer::drawUI()
{
	Res::get(FramebufferType::UI_BUFFER)->bind();
	glBlendFunc(GL_ONE, GL_ZERO);
	UIManager::draw();

}

void Renderer::postProcess()
{
	glBlendFunc(GL_ONE, GL_ZERO);
	Res::get(FramebufferType::DEFAULT)->bind();

	Model * m = Res::get(ModelType::MODEL_SQUARE_CENTERED);
	ShaderProgram * sp = Res::get(ShaderType::POST_PROCESS_SHADER);
	m->bind();
	sp->bind();
	sp->loadInteger("ui", 0);
	sp->loadInteger("world", 1);
	sp->loadInteger("effects", 2);

	sp->loadFloat("ui_trans", GameState::sliderValue);
	sp->loadFloat("ui_blue", GameState::ui_blue);

	sp->loadColor("screen_color", Screen::screenColor);
	sp->loadFloat("screen_color_percent", Screen::screenColorPercent);

	Res::get(FramebufferType::UI_BUFFER)->bindTexture(0);
	Res::get(FramebufferType::WORLD_BUFFER)->bindTexture(1);
	Res::get(FramebufferType::EFFECTS_BUFFER)->bindTexture(2);
	m->draw();


	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

void Renderer::preProcess()
{
	Res::get(FramebufferType::DEFAULT)->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Res::get(FramebufferType::WORLD_BUFFER)->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Res::get(FramebufferType::UI_BUFFER)->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Res::get(FramebufferType::EFFECTS_BUFFER)->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}
