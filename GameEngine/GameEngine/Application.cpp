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
	textbox.addTextToQueue(
		std::string(
			"#880088Lorem ipsum dolor sit amet, \n"
			"consectetur adipiscing elit, \n"
			"sed do eiusmod tempor incididunt \n"
			"ut labore et dolore magna aliqua. \n"
			"Ut enim ad minim veniam, quis \n"
			"nostrud exercitation ullamco \n"
			"laboris nisi ut aliquip ex ea \n"
			"commodo consequat. Duis aute irure \n"
			"dolor in reprehenderit in voluptate \n"
			"velit esse cillum dolore eu fugiat \n"
			"nulla pariatur. Excepteur sint \n"
			"occaecat cupidatat non proident, \n"
			"sunt in culpa qui officia deserunt \n"
			"mollit anim id est laborum. \n"
		
		));
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
