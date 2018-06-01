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

	UIManager::init();

	WeatherManager::init();

	Inventory inv;
	GameState::inv = &inv;

	//Rooms and the world
	World * world = World::getInstance();

	RoomFactory::CreateAllRooms();
	
	world->setCurrentRoom(std::string("Reading Room"));
	world->transition(world->getRoom(std::string("Clearing")));
	
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
	
	melody->weight = Weight::GHOST;
	Screen::setTargetPosition(&melody->pos);
	Screen::setMovementBehavior(Screen::followBehavior);

	dt = 1.0f / 60.0f;
	
	while (!Window::shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Window::pollEvents();
		timer.update();

		//float f = timer.getDeltaTime();

		//std::this_thread::sleep_for(std::chrono::microseconds(int(1000000*(dt-f))));
		
		//f = timer.getDeltaTime();
		//std::cout << f << std::endl;

		//Screen::follow(Vector2f(-1250, 1200));
		GameState::setGlobalDebug(std::to_string(timer.FPS()));

		Input::processInput(dt);
		UIManager::update(dt);

		WeatherManager::update(dt);

		//graph.update(dt);
		world->update(dt);
		Screen::update(dt);

		Screen::updateUniforms();
		

		Res::get(ShaderType::WATER_SHADER)->bind();
		Res::get(ShaderType::WATER_SHADER)->loadFloat("gameTime", timer.getGameTime());

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