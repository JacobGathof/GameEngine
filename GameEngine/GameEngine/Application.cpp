#include "Application.h"
#include <time.h>
#include "Renderer.h"
#include "Graph.h"
#include "AudioSystem.h"
#include "FastParticleSystem.h"
#include "SaveUtilities.h"
#include "Room.h"
#include "InteractionObject.h"
#include "BattleManager.h"

#include <thread>
#include <chrono>

#include "WeatherManager.h"

Application::Application(){}
Application::~Application(){}


void Application::run()
{
	srand((unsigned int)time(0));

	SaveUtilities::init();
	SaveUtilities::loadGame();

	Window::init("The Echo Effect", 800, 800);
	AudioSystem::init();

	ResourceManager::init();
	Screen::init();
	Input::init();

	Inventory inv;
	GameState::inv = &inv;
	inv.add(Res::get(CardType::EXCALIBUR));
	inv.add(Res::get(CardType::FIREBALL));
	inv.add(Res::get(CardType::FIREBALL));
	inv.add(Res::get(CardType::EXCALIBUR));
	inv.add(Res::get(CardType::SHADOW_STEP));

	inv.add(Res::get(WeaponType::SWORD));
	inv.add(Res::get(WeaponType::BOW));

	UIManager::init();

	WeatherManager::init();


	//Rooms and the world
	World * world = World::getInstance();

	RoomFactory::CreateAllRooms();
	
	world->setCurrentRoom(std::string("Reading Room"));
	//world->transition(world->getRoom(std::string("Clearing")));
	
	Res::get(ShaderType::TEXT_SHADER)->bind();
	Res::get(ShaderType::TEXT_SHADER)->loadFloat("aspect_ratio", Window::getAspectRatio());

	//RainParticleSystem *sys = new RainParticleSystem();
	//sys->parentPosition = &melody.pos;
	//sys->startColor = Color::DarkBlue;
	//sys->endColor = Color::DarkPurple;

	//melody.addEffect(sys);

	GameTimer timer;
	timer.setTickLength(1.0f);

	//Circle circ(Vector2f(0,0), 256.0f);
	
	Graph graph;
	GameState::graph = &graph;

	float dt;

	Window::show();
	//Window::close();
	
	Object * melody = world->getObject(std::string("Player"));
	melody->pos = Vector2f(0, 0);
	
	melody->weight = Weight::GHOST;
	Screen::setTargetPosition(&melody->pos);
	Screen::setMovementBehavior(Screen::followBehavior);

	dt = 1.0f / 60.0f;
	
	while (!Window::shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Window::pollEvents();

		timer.update();

		Res::get(ShaderType::LIGHT_SHADER)->bind();
		Res::get(ShaderType::LIGHT_SHADER)->loadFloat("gameTime", timer.getGameTime());


		Input::processInput(dt);
		UIManager::update(dt);

		if (!GameState::isGamePaused()) {

			WeatherManager::update(dt);

			//graph.update(dt);
			world->update(dt);
			Screen::update(dt);

		}

		Screen::updateUniforms();
		Renderer::draw();
		Window::swapBuffers();
		
	}

	SaveUtilities::saveGame();


	World::clean();
	ResourceManager::clean();
	UIManager::clean();
	AudioSystem::clean();

	WeatherManager::clean();

	Window::destroy();

}

int main() {
	Application app;
	app.run();

	//system("pause");
	return 0;
}