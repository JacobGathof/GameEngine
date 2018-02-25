#include "Application.h"
#include <time.h>
#include "Renderer.h"
#include "Graph.h"

Application::Application(){}
Application::~Application(){}


void Application::run()
{
	srand(time(0));

	Window::init("The Echo Effect", 800, 800);

	ResourceManager::init();
	Screen::init();
	Input::init();

	UIManager::init();

	//Rooms and the world
	World * world = World::getInstance();
	Room room;
	Room room2;

	// Start making objects here
	PlayerAI playerAi;
	Input::ai = &playerAi;
	Player melody(TextureType::TEXTURE_MELODY, Vector2f(0,0), Vector2f(256,256), &playerAi);
	LivingObject structure(TextureType::TEXTURE_MELODY, Vector2f(-300, -100), Vector2f(256, 256), 100, 100);
	RunAwayAI follow(&melody);
	structure.setAI(&follow);
	structure.moveSpeed = 600;
	//TransitionObject trans(TextureType::TEXTURE_TEST, Vector2f(-.5, .5), Vector2f(.5, .5), &room2);
	//Object structure2(TextureType::TEXTURE_TEST, Vector2f(-.5, 1), Vector2f(.5, .5));
	
	world->setCurrentRoom(&room);
	room.addObject(&melody);
	room.addObject(&structure);
	//room.addObject(&trans);

	Res::get(ShaderType::TEXT_SHADER)->bind();
	Res::get(ShaderType::TEXT_SHADER)->loadFloat("aspect_ratio", Window::getAspectRatio());

	DefaultParticleSystem sys;
	sys.parentPosition = &melody.pos;
	sys.startColor = Color::DarkBlue;
	sys.endColor = Color::DarkPurple;

	GameTimer timer;
	timer.setTickLength(1.0f);

	Circle circ(Vector2f(0,0), 256.0f);

	Graph graph;
	
	float dt;
	Window::show();
	while (!Window::shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Window::pollEvents();
		timer.update();
		dt = timer.getDeltaTime();


		Screen::follow(melody.pos);
		GameState::setGlobalDebug(std::to_string(timer.FPS()));

		Input::processInput(dt);
		UIManager::update(dt);
		graph.update(dt);


		world->update(dt);

		//sys.update(dt);
		//sys.draw();


		//circ.draw(timer.getGameTime());


		

		Renderer::draw();


		Window::swapBuffers();
	}

	ResourceManager::clean();
	UIManager::clean();

	Window::destroy();

}

int main() {
	Application app;
	app.run();

	system("pause");
	return 0;
}
