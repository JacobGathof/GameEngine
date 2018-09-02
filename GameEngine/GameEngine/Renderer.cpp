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
	//drawEffects();

	postProcess();
	

}

void Renderer::drawWorld()
{

	Res::get(FramebufferType::EXTRA_BUFFER_1)->bind();
	glEnable(GL_DEPTH_TEST);
	World::getInstance()->drawObjectsInverted();
	glDisable(GL_DEPTH_TEST);

	Res::get(FramebufferType::OBJECT_BUFFER)->bind();
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	World::getInstance()->drawTerrain();


	Res::get(FramebufferType::OBJECT_BUFFER)->bind();
	glEnable(GL_DEPTH_TEST);
	World::getInstance()->drawObjects();
	glDisable(GL_DEPTH_TEST);



	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	Res::get(FramebufferType::EFFECTS_BUFFER)->bind();
	World::getInstance()->drawLights();
	glBlendFunc(GL_ONE, GL_ZERO);
	//World::getInstance()->drawObjectsNegative();
	



	drawEffects();

	//World::getInstance()->draw();
}


void Renderer::drawEffects()
{
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	Res::get(FramebufferType::OBJECT_BUFFER)->bind();
	World::getInstance()->drawEffects();
	//WeatherManager::drawAmbientLight();
	World::getInstance()->drawHitboxes();
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
	sp->loadInteger("terrain", 1);
	sp->loadInteger("effects", 2);
	sp->loadInteger("objects", 3);

	sp->loadFloat("ui_trans", GameState::sliderValue);
	sp->loadFloat("ui_blue", GameState::ui_blue);

	sp->loadColor("screen_color", Screen::screenColor);
	sp->loadFloat("screen_color_percent", Screen::screenColorPercent);
	sp->loadColor("ambientLight", Color(GameState::red, GameState::green, GameState::blue, 1));

	Res::get(FramebufferType::UI_BUFFER)->bindTexture(0);
	Res::get(FramebufferType::TERRAIN_BUFFER)->bindTexture(1);
	Res::get(FramebufferType::EFFECTS_BUFFER)->bindTexture(2);
	Res::get(FramebufferType::OBJECT_BUFFER)->bindTexture(3);
	m->draw();


	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);



	//drawDebugWindow();


}

void Renderer::preProcess()
{
	Res::get(FramebufferType::DEFAULT)->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Res::get(FramebufferType::OBJECT_BUFFER)->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Res::get(FramebufferType::TERRAIN_BUFFER)->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Res::get(FramebufferType::UI_BUFFER)->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Res::get(FramebufferType::EFFECTS_BUFFER)->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	Res::get(FramebufferType::EXTRA_BUFFER_1)->bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::drawDebugWindow()
{

	Model* m = Res::get(ModelType::MODEL_SQUARE);
	ShaderProgram* sp = Res::get(ShaderType::UI_SOLID_SHADER);
	sp->bind();
	m->bind();

	sp->loadVector2f("translate", Vector2f(0, 0));
	sp->loadVector2f("scale", Vector2f(200, 200));
	sp->loadColor("color", Color::Black);


	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	m->draw();
	glBlendFunc(GL_ONE, GL_ZERO);




	
	sp = Res::get(ShaderType::UI_IMAGE_SHADER);
	sp->bind();
	m->bind();

	sp->loadVector2f("translate", Vector2f(0, 200));
	sp->loadVector2f("scale", Vector2f(200, -200));

	Res::get(FramebufferType::EFFECTS_BUFFER)->bindTexture(0);

	sp->loadVector2f("dim", Vector2f(1, 1));
	sp->loadVector2f("offset", Vector2f(0, 0));
	sp->loadColor("color", Color::White);


	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	m->draw();
	glBlendFunc(GL_ONE, GL_ZERO);






}
