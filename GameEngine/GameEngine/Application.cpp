#include "Application.h"
#include "List.h"
#include "GameState.h"

Application::Application(){}
Application::~Application(){}


void Application::run()
{
	std::cout << "-=-=-=-Running Tests-=-=-=-" << std::endl;

	Window::init("Hello World", 800, 800);

	ResourceManager::init();
	Screen::init();
	Input::init();
	//Rooms and the world
	World * world = World::getInstance();
	Room room;
	Room room2;

	// Start making objects here
	PlayerAI playerAi;
	Input::ai = &playerAi;
	Player melody(TextureType::TEXTURE_MELODY, Vector2f(.5,.5), Vector2f(256,256), &playerAi);
	Object structure(TextureType::TEXTURE_TEST, Vector2f(-.5, -.5), Vector2f(.5, .5));
	TransitionObject trans(TextureType::TEXTURE_TEST, Vector2f(-.5, .5), Vector2f(.5, .5), &room2);
	//Object structure2(TextureType::TEXTURE_TEST, Vector2f(-.5, 1), Vector2f(.5, .5));
	
	world->setCurrentRoom(&room);
	room.addObject(&melody);
	room2.addObject(&structure);
	room.addObject(&trans);

	Res::get(ShaderType::TEXT_SHADER)->bind();
	Res::get(ShaderType::TEXT_SHADER)->loadFloat("aspect_ratio", Window::getAspectRatio());

	Textbox tb;
	StatsPage sp;

	Text text(Vector2f(100, 100), std::string(
		"DON'T PRINT THIS"
	), Vector2f(64.0f, 64.0f), FontManager::get(FontType::DEFAULT));

	text.resetLength();

	GameTimer timer;
	timer.setTickLength(0.01f);

	Circle circ(Vector2f(0,0), 1.0f);
	sp.show();
	
	float dt;
	Window::show();
	while (!Window::shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Window::pollEvents();
		timer.update();
		dt = timer.getDeltaTime();

		sp.update(dt);

		if (timer.tick()) {
			text.addLetter();
		}

		GameState::setGlobalDebug(std::to_string(timer.getGameTime()));

		tb.draw();
		sp.draw();
		text.draw();

		Input::processInput(dt);

		world->update(dt);
		world->draw();

		circ.draw(timer.getGameTime());

		Window::swapBuffers();
	}

	ResourceManager::clean();

	Window::destroy();

	std::cout << "-=-=-=-Finished Tests-=-=-=-" << std::endl;

}

int main() {
	Application app;
	app.run();

	system("pause");
	return 0;
}
