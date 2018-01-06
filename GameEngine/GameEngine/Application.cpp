#include "Application.h"


Application::Application(){}
Application::~Application(){}

void Application::test() {

	std::cout << "-=-=-=-Running Tests-=-=-=-" << std::endl;


	Window::init("Hello World", 800, 800);
	Timer timer;
	timer.setTickLength(0.05f);

	ShaderManager::init();
	FontManager::init();

	Texture tex("res_test/Calamity.png");

	Textbox textbox;
	Text text(Vector2f(-1, 1), std::string(
		"#880088Lorem ipsum #ff0000dolor sit amet, \n"
		"consec#aaaafftetur adipiscing elit, \n"
		"sed do eiusmod tempor incididunt \n"
		"ut labore et dolore magna aliqua. \n"
		"Ut enim ad minim veniam, quis \n"
		"nostrud exercit#aaff00ation ullamco %\n"
		"laboris nisi ut aliquip ex ea \n"
		"commodo consequat. Duis aute irure \n"
		"dolor in reprehenderit in voluptate \n"
		"velit esse cillum dolore eu fugiat \n"
		"nulla pariatur. Excepteur sint \n"
		"occaecat cupidatat non proident, \n"
		"sunt in culpa qui officia deserunt \n"
		"mollit anim id est laborum. \n"

	) , Vector2f(.5f, .5f), FontManager::get(FontType::DEFAULT));

	text.resetLength();

	// Add or remove single "/" on the line below to show window

	//*
	Window::show();
	while (!Window::shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Window::pollEvents();
		timer.update();

		if (timer.tick()) {
			text.addLetter();
		}

		text.render();

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
