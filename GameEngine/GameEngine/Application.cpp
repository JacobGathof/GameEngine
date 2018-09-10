#include "Application.h"
#include <time.h>
#include "Renderer.h"
#include "Graph.h"
#include "AudioSystem.h"
#include "FastParticleSystem.h"
#include "SaveUtilities.h"
#include "Room.h"
#include "BattleManager.h"

#include "WeatherManager.h"
#include "GlobalActionInvoker.h"

#include "BezierSpline.h"
#include "Midi.h"
#include "MidiScheduler.h"



#include "AbstractObjectComponent.h"
#include "AnimatedComponent.h"
#include "CollidableComponent.h"
#include "InteractableComponent.h"
#include "LivingComponent.h"



#include "ScriptManager.h"


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
	GlobalActionInvoker::init();
	
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

	Midi* midi = new Midi("res/audio/test.mid");
	MidiScheduler::loadMidi(midi);

	//Rooms and the world
	World * world = World::getInstance();

	RoomFactory::CreateAllRooms();
	
	world->setCurrentRoom(World::RoomNames::READING_ROOM);

	//world->transition(world->getRoom(std::string("Clearing")));
	
	Res::get(ShaderType::TEXT_SHADER)->bind();
	Res::get(ShaderType::TEXT_SHADER)->loadFloat("aspect_ratio", Window::getAspectRatio());

	Res::get(ShaderType::TEXT_WORLD_SHADER)->bind();
	Res::get(ShaderType::TEXT_WORLD_SHADER)->loadFloat("aspect_ratio", Window::getAspectRatio());

	//RainParticleSystem *sys = new RainParticleSystem();
	//sys->parentPosition = &melody.pos;
	//sys->startColor = Color::DarkBlue;
	//sys->endColor = Color::DarkPurple;

	//melody.addEffect(sys);

	GameTimer timer;
	timer.setTickLength(1.0f);

	//Circle circ(Vector2f(0,0), 256.0f);
	
	//Graph graph;
	//GameState::graph = &graph;

	Window::show();
	//Window::close();
	
	Object * melody = world->getObject(std::string("Player"));
	melody->pos = Vector2f(0, 0);

	//melody->weight = Weight::GHOST;
	Screen::setTargetPosition(&melody->pos);
	Screen::setMovementBehavior(Screen::followBehavior);


	std::cout << "Objects Created: " << Object::numCreated << std::endl;


	float dt;

	while (!Window::shouldClose()) {
		Window::pollEvents();

		timer.update();
		dt = timer.getDeltaTime();

		//std::cout << timer.FPS() << std::endl;
		Res::uploadGlobalUniform("gameTime", timer.getGameTime());
		Res::uploadGlobalUniform("window_scale", Vector2f(Window::WINDOW_WIDTH, Window::WINDOW_HEIGHT));

		Input::processInput(dt);
		UIManager::update(dt);

		if (!GameState::isGamePaused()) {

			GlobalActionInvoker::update(dt);
			WeatherManager::update(dt);

			//graph.update(dt);
			Res::scriptManager->update(dt);
			world->update(dt);
			Screen::update(dt);
			MidiScheduler::update(dt);
		}

		Screen::updateUniforms();
		Renderer::draw();

		/*
		Input::ai->spline.draw();
		Input::ai->line.draw();
		Input::ai->line2.draw();
		*/

		GameState::applicationState.interactionName = "";

		Window::swapBuffers();
		
		timer.sleep();
	}

	delete midi;

	SaveUtilities::saveGame();


	World::clean();
	ResourceManager::clean();
	UIManager::clean();
	AudioSystem::clean();

	WeatherManager::clean();
	GlobalActionInvoker::clean();

	std::cout << "Objects Deleted: " << Object::numDeleted << std::endl;

	Window::destroy();

}

int main() {
	Application app;
	app.run();

	system("pause");
	return 0;
}