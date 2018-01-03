#include "Application.h"


Application::Application(){}
Application::~Application(){}

void Application::test() {

	std::cout << "-=-=-=-Running Tests-=-=-=-" << std::endl;


	Window::init("Hello World", 400, 400);

	ShaderManager::init();
	FontManager::init();

	Font font("res_test/font.fnt", "res_test/font.png");
	Texture tex("res_test/Calamity.png");

	Textbox textbox;
	textbox.addTextToQueue(std::string("This is the first string"));
	textbox.advanceText();

	//Text text(Vector2f(-1,1), std::string("Hello World\nNew Line"), Vector2f(1,1), &font);
	//text.setText(std::string("New string"));

	while (!Window::shouldClose()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		Window::pollEvents();

		textbox.render();

		Window::swapBuffers();
	}

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
