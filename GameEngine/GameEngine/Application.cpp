#include "Application.h"
#include <time.h>
#include "Renderer.h"
#include "Graph.h"
#include "AudioSystem.h"
#include "FastParticleSystem.h"
#include "SaveUtilities.h"
#include "Room.h"
#include "ShadowMap.h"
#include "InteractionObject.h"

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

	//Rooms and the world
	World * world = World::getInstance();

	RoomFactory::CreateAllRooms();

	//TODO:  Make this one call to world
	world->setCurrentRoom(world->getRoom(std::string("Reading Room")));
	

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


	ShadowMap map;

	float dt;
	Window::show();
	//Window::close();

	Object * melody = world->getObject(std::string("Melody"));
	

	while (!Window::shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Window::pollEvents();
		timer.update();
		dt = timer.getDeltaTime();

		Screen::follow(melody->pos);
		
		//Screen::follow(Vector2f(-1250, 1200));
		GameState::setGlobalDebug(std::to_string(timer.FPS()));

		Input::processInput(dt);
		UIManager::update(dt);

		graph.update(dt);

		world->update(dt);

		Screen::updateUniforms();
		//map.calculateShadowMap(melody->pos);
		
		Res::get(ShaderType::BASIC_SHADER)->bind();
		Res::get(TextureType::TEXTURE_DEFAULT)->bind();
		Res::get(ModelType::MODEL_SQUARE_CENTERED)->bind();
		Res::get(ShaderType::BASIC_SHADER)->loadVector2f("translate", Vector2f(0, 0));
		Res::get(ShaderType::BASIC_SHADER)->loadVector2f("scale",Vector2f(32, 32));
		//Res::get(ModelType::MODEL_SQUARE_CENTERED)->draw();


		Res::get(ShaderType::PARTICLE_FAST_SHADER)->loadFloat("gameTime", timer.getGameTime());
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
	Window::destroy();

}

int main() {
	Application app;
	app.run();

	//system("pause");
	return 0;
}
