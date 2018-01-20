#include "Application.h"


Application::Application(){}
Application::~Application(){}


void Application::run()
{
	std::cout << "-=-=-=-Running Tests-=-=-=-" << std::endl;

	Window::init("Hello World", 800, 800);

	ShaderManager::init();
	FontManager::init();
	ModelManager::init();
	TextureManager::init();

	ShaderManager::get(ShaderType::TEXT_SHADER)->bind();
	ShaderManager::get(ShaderType::TEXT_SHADER)->loadFloat("aspect_ratio", Window::getAspectRatio());

	Text text(Vector2f(-1, 1), std::string(
		"Lorem ipsum dolor sit amet, "
		"consectetur adipiscing elit, "
		"sed do eiusmod tempor incididunt "
		"ut labore et dolore magna aliqua. "
		"Ut enim ad minim veniam, quis "
		"nostrud exercitation ullamco "
		"laboris nisi ut aliquip ex ea "
		"commodo consequat. Duis aute irure "
		"dolor in reprehenderit in voluptate "
		"velit esse cillum dolore eu fugiat "
		"nulla pariatur. Excepteur sint "
		"occaecat cupidatat non proident, "
		"sunt in culpa qui officia deserunt "
		"mollit anim id est laborum."

	), Vector2f(0.25f, 0.25f), FontManager::get(FontType::DEFAULT));

	text.resetLength();

	Timer timer;
	timer.setTickLength(0.01f);


	// Code Toggle: Remove single "/" on the line below to hide window

	//*
	float dt;
	Window::show();
	while (!Window::shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Window::pollEvents();
		timer.update();
		dt = timer.getDeltaTime();

		if (timer.tick()) {
			text.addLetter();
		}

		text.render();

		Input::processInput(dt);

		Window::swapBuffers();
	}
	/*/
	std::cout << "Here"
	//*/

	ShaderManager::clean();
	FontManager::clean();
	ModelManager::clean();
	TextureManager::clean();

	Window::destroy();

	std::cout << "-=-=-=-Finished Tests-=-=-=-" << std::endl;

}

int main() {
	Application app;
	app.run();

	system("pause");
	return 0;
}
