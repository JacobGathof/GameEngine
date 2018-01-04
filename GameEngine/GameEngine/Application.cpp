#include "Application.h"


Application::Application(){}
Application::~Application(){}

void Application::test() {

	std::cout << "-=-=-=-Running Tests-=-=-=-" << std::endl;


	Window::init("Hello World", 800, 800);

	ShaderManager::init();
	FontManager::init();

	Texture tex("res_test/Calamity.png");

	Textbox textbox;
	textbox.addTextToQueue(std::string("This is the\n first string"));
	textbox.advanceText();


	// Add or remove single "/" on the line below to show window

	//*
	Window::show();
	while (!Window::shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Window::pollEvents();

		textbox.render();

		Window::swapBuffers();
	}
	//*/

	Window::destroy();
	ShaderManager::clean();
	FontManager::clean();


	std::cout << "-=-=-=-Finished Tests-=-=-=-" << std::endl;

}


void Application::run()
{
	test();
}

int main() {
	Application app;
	app.run();

	system("pause");
	return 0;
}
